#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/minplus_convolution.hpp"

ll dp[10'000'000];

void solve() {
  LL(N);
  VEC(int, A, N);

  vc<int> lo(N + 1, infty<int>), hi(N + 1, -infty<int>);
  vc<int> S(N + 1);

  auto dfs = [&](auto &dfs, int L, int R, int a, int b,
                 bool dryrun) -> vc<int> {
    // dp[L][a,b) から dp[R] への遷移を行う
    // return: 間の A のソート列
    chmin(lo[L], a), chmax(hi[L], b);
    chmin(lo[R], a), chmax(hi[R], b + (R - L));
    ll *dpL = dp + S[L];
    ll *dpR = dp + S[R];
    if (R == L + 1) {
      if (dryrun) return {};
      int x = A[L];
      if (x == -1) {
        FOR(i, a, b) {
          ll v = dpL[i - lo[L]];
          int j = (i >= L - i ? i + 1 : i);
          chmin(dpR[j - lo[R]], v);
        }
        return {};
      } else {
        FOR(i, a, b) {
          ll v = dpL[i - lo[L]];
          chmin(dpR[i - lo[R]], v);
          chmin(dpR[i + 1 - lo[R]], v + x);
          assert(0 <= i - lo[R]);
        }
        return {x};
      }
    }
    int M = (L + R) / 2;
    // [c,d) 部分だけが問題です
    // [a,c), [b,d) は直接遷移可能です
    // c + (R-L) >= R - (c + (R - L))
    int c = ceil<int>(2 * L - R, 2);
    // d >= R - d
    int d = ceil<int>(R, 2);
    chmax(c, a), chmin(d, b);
    assert(c <= d);

    vc<int> X = dfs(dfs, L, M, c, d, dryrun);
    vc<int> Y = dfs(dfs, M, R, c, d + (M - L), dryrun);

    if (dryrun) return {};
    vc<int> T(len(X) + len(Y));
    merge(all(X), all(Y), T.begin());
    int T2 = R - L - len(T);
    // [a,c) と [d,b) からの遷移を行う
    if (a < c) {
      vi F(c - a);
      FOR(i, a, c) F[i - a] = dpL[i - lo[L]];
      vi Tc = cumsum<ll>(T);
      F = minplus_convolution_arbitrary_convex<ll>(F, Tc);
      FOR(i, len(F)) { chmin(dpR[(i + a) - lo[R]], F[i]); }
    }
    if (d < b) {
      vi F(b - d);
      FOR(i, d, b) F[i - d] = dpL[i - lo[L]];
      vi Tc = cumsum<ll>(T);
      F = minplus_convolution_arbitrary_convex<ll>(F, Tc);
      FOR(i, len(F)) { chmin(dpR[(i + d + T2) - lo[R]], F[i]); }
    }

    return T;
  };

  dfs(dfs, 0, N, 0, 1, true);
  FOR(i, N + 1) S[i] = hi[i] - lo[i];
  S = cumsum<int>(S);

  FOR(i, S[N + 1]) dp[i] = infty<ll>;
  dp[0] = 0;

  dfs(dfs, 0, N, 0, 1, false);

  vi ANS(N + 1);
  FOR(i, N + 1) ANS[i] = dp[S[N] + i];
  FOR_R(i, N) chmin(ANS[i], ANS[i + 1]);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}