#include "my_template.hpp"
#include "other/io.hpp" o
#include "mod/modint.hpp"

using mint = modint998;

/*
結局最後以外は 1 / n - CNT 重み？
*/

void solve() {
  LL(N);
  vi S(N), T(N);
  FOR(i, N) read(S[i], T[i]), --S[i], --T[i];

  {
    vi X;
    concat(X, S, T);
    UNIQUE(X);
    for (auto &x : S) x = LB(X, x);
    for (auto &x : T) x = LB(X, x);
    N = len(X);
  }

  ll M = len(S);
  SHOW(N, M, S, T);

  vv(int, CNT, N, N);

  FOR_R(L, N) {
    FOR(k, M) if (S[k] == L) { CNT[L][T[k]] += 1; }
    FOR(i, N - 1) CNT[L][i + 1] += CNT[L][i];
    if (L + 1 < N) FOR(i, N) CNT[L][i] += CNT[L + 1][i];
  }

#ifdef LOCAL
  FOR(L, N) FOR(R, L, N) {
    int cnt = 0;
    FOR(i, M) cnt += (L <= S[i] && T[i] <= R);
    assert(cnt == CNT[L][R]);
  }
#endif

  vv(mint, dp, N, N);
  vv(mint, SM_L, N, N);
  vv(mint, SM_R, N, N);
  vv(mint, SM, N, N);

  auto upd = [&](int L, int R, mint x) -> void {
    SHOW(L, R, x);
    dp[L][R] = x;
    SM_L[L][R] = x;
    SM_R[L][R] = x;
    SM[L][R] = x;
    if (L < R) {
      SM_L[L][R] += SM_L[L][R - 1];
      SM_R[L][R] += SM_R[L + 1][R];
      SM[L][R] += SM[L + 1][R];
      SM[L][R] += SM[L][R - 1];
      if (L + 1 <= R - 1) SM[L][R] -= SM[L + 1][R - 1];
    }
  };

  vvc<int> SID(N), TID(N);
  FOR(i, M) SID[S[i]].eb(i);
  FOR(i, M) TID[T[i]].eb(i);

  FOR_R(L, N) FOR(R, L, N) {
    if (CNT[L][R] == 0) continue;
    mint ANS = 0;
    // 1 手目
    for (auto &p : SID[L]) {
      if (T[p] == R) {
        ANS += 1;
      }
    }

    if (L == 0 && R == 2) SHOW(L, R, ANS);
    // 両側拡張
    if (L + 2 <= R) {
      int ok = 0;
      for (int p : SID[L]) ok += (T[p] == R);
      ANS += SM[L + 1][R - 1] * ok;
    }

    if (L == 0 && R == 2) SHOW(L, R, ANS);

    // 左側拡張
    for (int p : SID[L]) {
      int t = T[p];
      if (R < t) continue;
      // FOR(i, L + 1, t + 1) { ANS += dp[i][R]; }
      if (L + 1 <= R) ANS += SM_R[L + 1][R];
      if (t + 1 <= R) ANS -= SM_R[t + 1][R];
    }
    if (L == 0 && R == 2) SHOW(L, R, ANS);
    // 右側拡張
    for (int p : TID[R]) {
      int t = S[p];
      if (t < L) continue;
      // FOR(i, t, R) ANS += dp[L][i];
      if (L <= R - 1) ANS += SM_L[L][R - 1];
      if (L <= t - 1) ANS -= SM_L[L][t - 1];
    }

    if (L == 0 && R == 2) SHOW(L, R, ANS);

    if (L == 0 && R == N - 1) {
      ANS = fact<mint>(M - 1) * ANS;
      return print(ANS);
    } else {
      SHOW(L, R, M, CNT[L][R]);
      ANS *= inv<mint>(M - CNT[L][R]);
      upd(L, R, ANS);
    }
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}