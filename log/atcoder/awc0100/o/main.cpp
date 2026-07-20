#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  FOR(i, N) A.eb(A[i]);

  vv(ll, dp, 2 * N + 1, 2 * N + 1, infty<ll>);
  vv(ll, best, 2 * N + 1, 2 * N + 1);
  FOR(i, 2 * N) {
    // dp[i][i + 1] = A[i];
    dp[i][i + 1] = 0;
    best[i][i + 1] = i + 1;
  }

  auto Ac = cumsum<ll>(A);

  FOR(n, 2, N + 1) {
    FOR(L, 2 * N - n + 1) {
      int R = L + n;
      int s = best[L][R - 1], t = best[L + 1][R];
      chmax(s, L + 1);
      chmin(t, R - 1);
      FOR(M, s, t + 1) {
        if (chmin(dp[L][R], dp[L][M] + dp[M][R])) best[L][R] = M;
      }
      dp[L][R] += Ac[R] - Ac[L];
      SHOW(L, R, s, t, best[L][R], dp[L][R]);
    }
  }

  ll ans = infty<ll>;
  FOR(i, N + 1) chmin(ans, dp[i][i + N]);
  print(ans);
}

signed main() {
  solve();
  return 0;
}