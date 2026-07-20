#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"

/*
タイブレイクは左が小さいと思って cartesian tree
木構造を決めると，bottom up に値を貪欲に決める形になる
*/

using mint = modint107;

mint dp[110][110][110];
mint dpc[110][110][110];

void solve() {
  LL(N);
  VEC(ll, A, N);
  // for (auto& x : A) --x;

  FOR_R(L, N + 1) FOR(R, L, N + 1) {
    if (L == R) {
      dp[L][R][0] = 1;
    } else {
      FOR(M, L, R) {
        FOR(x, 1, A[M] + 1) {
          mint ans = 0;
          // max(left, right+1)==x
          // [0,x], [0,x-1]
          ans += dpc[L][M][x] * dpc[M + 1][R][x - 1];
          // ひく
          if (x >= 2) ans -= dpc[L][M][x - 1] * dpc[M + 1][R][x - 2];
          dp[L][R][x] += ans;
          SHOW(L, M, R, ans);
        }
      }
    }
    FOR(x, N + 1) dpc[L][R][x] = dp[L][R][x];
    FOR(x, N + 1) dpc[L][R][x + 1] += dpc[L][R][x];
    FOR(x, N + 1) SHOW(L, R, x, dp[L][R][x]);
  }

  mint ANS = dpc[0][N][N + 1];
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
