#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"

using mint = modint998;

// mint dp[510][510][510];
// mint DP[510][510];
// void solve() {
//   LL(N);
//   VEC(ll, A, N);
//   vvv(mint, dp, N + 1, N + 1, N + 1);
//   FOR(i, N + 1) dp[i][i][0] = 1;

//   FOR_R(L, N + 1) FOR(R, L, N + 1) {
//     FOR(i, N + 1) dp[L][R][i] = 0;
//     DP[L][R] = 0;
//     if (L == R) {
//       dp[L][R][0] = 1;
//       DP[L][R] = 1;
//       continue;
//     }
//     FOR(M, L, R) {
//       mint x = 0;
//       if (A[M] == -1) {
//         x += DP[L][M];
//       } else {
//         x += dp[L][M][A[M]];
//       }
//       x *= C<mint>(R - L - 1, M - L);
//       DP[L][R] += DP[M + 1][R] * x;
//       FOR(k, N) { dp[L][R][k + 1] += dp[M + 1][R][k] * x; }
//     }
//   }

//   mint ANS = DP[0][N];
//   print(ANS);
// }

/*
すごい
まず dp[L][R][k] で参照する必要があるのは、dp[L][R][0 to A[R]] の形だけ
さらに sum(A)<=N 以外は答が 0

メモリも 2乗になっている
*/

mint dp[510][1010];
mint DP[510][1010];

void solve() {
  LL(N);
  VEC(ll, A, N);
  A.eb(-1);

  vc<int> ptr(N + 2);
  FOR(i, N + 1) {
    int k = A[i] + 1;
    ptr[i + 1] = ptr[i] + k;
  }

  if (ptr[N] > N + N + 1) return print(0);

  auto f = [&](int L, int R, int k) -> mint& {
    assert(k <= A[R]);
    return dp[L][ptr[R] + k];
  };

  FOR_R(L, N + 1) FOR(R, L, N + 1) {
    // FOR(i, N + 1) dp[L][R][i] = 0;
    FOR(j, A[R] + 1) f(L, R, j) = 0;

    DP[L][R] = 0;
    if (L == R) {
      // dp[L][R][0] = 1;
      if (A[R] != -1) f(L, R, 0) = 1;
      DP[L][R] = 1;
      continue;
    }
    FOR(M, L, R) {
      mint x = 0;
      if (A[M] == -1) {
        x += DP[L][M];
      } else {
        // x += dp[L][M][A[M]];
        x += f(L, M, A[M]);
      }
      x *= C<mint>(R - L - 1, M - L);
      DP[L][R] += DP[M + 1][R] * x;
      // FOR(k, N) { dp[L][R][k + 1] += dp[M + 1][R][k] * x; }
      FOR(k, A[R]) f(L, R, k + 1) += f(M + 1, R, k) * x;
    }
  }

  mint ANS = DP[0][N];
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}