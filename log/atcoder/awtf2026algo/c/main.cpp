#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/2d/convolution2d.hpp"

using mint = modint998;

// 空も許して K ブロックに分割します
mint solve(vi A, ll K) {
  ll N = len(A);
  // vv(mint, F, N, N);
  // FOR(a, N) FOR(b, N) {
  //   if (a + b >= N) break;
  //   FOR(k, K) { F[a][b] += mint(k + 1).pow(b) * mint(k).pow(a); }
  //   F[a][b] *= C<mint>(a + b, a);
  // }

  vv(mint, F, 0, N);
  auto add_row = [&](int a) -> void {
    vc<mint> row(N);
    FOR(b, N) {
      if (a + b >= N) break;
      FOR(k, K) { row[b] += mint(k + 1).pow(b) * mint(k).pow(a); }
      row[b] *= C<mint>(a + b, a);
    }
    F.eb(row);
  };

  vv(mint, dp, 1, N);
  dp[0][0] = 1;

  FOR(idx, N) {
    int n = idx + 1;
    vv(mint, newdp, n + 1, N);

    add_row(idx);
    vv(mint, G, n, N);
    FOR(i, n) FOR(j, N) G[i][j] = dp[n - 1 - i][j];
    G = convolution2d<mint>(G, F, true);
    FOR(i, n) FOR(j, N) { newdp[i][j] = G[n - 1 - i][j] * A[idx]; }
    newdp.eb(vc<mint>(N));
    FOR(a, n) FOR(b, N) {
      if (dp[a][b] == 0) continue;
      mint x = dp[a][b];
      // case 2. smaller として確保
      if (a + 1 < N) newdp[a + 1][b] += x * (a + 1);

      // case 3. large 用の空マスに入れる
      if (b > 0) newdp[a][b - 1] += x * b;
    }
    swap(dp, newdp);
  }
  mint ANS = dp[0][0];
  SHOW(A, K, ANS);
  return dp[0][0];
}

void solve() {
  LL(N);
  VEC(ll, A, N);
  for (auto &x : A) ++x;

  vc<mint> F(N + 1);
  FOR(n, 1, N + 1) F[n] = solve(A, n);
  SHOW(F);

  /*
  F から ANS への変換規則は？
  いったん途中状態を経由すると分かりやすいと思う
  G: non-empty な n グループに分割する
  F[n] = sum_{n>=m} G[m] binom(n,m)
  */
  vc<mint> G(N + 1);
  FOR(n, 1, N + 1) {
    G[n] = F[n];
    FOR(m, n) G[n] -= C<mint>(n, m) * G[m];
  }

  /*
  ANS[n]: descent で切ったときにちょうど n グループあります
  G[n] = sum_{m<=n} ANS[m] C(N-m,n-m) かな
  */
  vc<mint> ANS(N + 1);
  FOR(n, 1, N + 1) {
    ANS[n] = G[n];
    FOR(m, n) ANS[n] -= C<mint>(N - m, n - m) * ANS[m];
  }

  ANS.erase(ANS.begin());
  print(ANS);
}

signed main() { solve(); }