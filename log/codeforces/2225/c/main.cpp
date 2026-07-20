#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  STR(A, B);
  vi dp(N + 1, infty<ll>);
  dp[0] = 0;
  FOR(i, N) {
    {
      ll x = (A[i] == B[i] ? 0 : 1);
      chmin(dp[i + 1], dp[i] + x);
    }
    if (i + 2 <= N) {
      ll x = 0;
      x += (A[i] == A[i + 1] ? 0 : 1);
      x += (B[i] == B[i + 1] ? 0 : 1);
      chmin(dp[i + 2], dp[i] + x);
    }
  }
  print(dp[N]);
}

signed main() {
  INT(T);
  FOR(T) solve();
}