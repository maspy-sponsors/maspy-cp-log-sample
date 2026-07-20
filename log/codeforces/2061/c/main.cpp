#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  VEC(ll, A, N);
  if (N == 1) {
    if (A[0] == 0) return print(2);
    return print(1);
  }

  vv(mint, dp, 2, 2);
  // o, o
  if (A[0] == 0 && A[1] == 0) dp[1][1] = 1;
  // o, x
  if (A[0] == 0) dp[1][0] = 1;
  // x, o
  if (A[1] == 1) dp[0][1] = 1;

  FOR(i, N - 2) {
    ll a = A[i], b = A[i + 1], c = A[i + 2];
    vv(mint, newdp, 2, 2);
    FOR(s, 2) FOR(t, 2) {
      if (s == 0 && t == 0) continue;
      if (dp[s][t] == 0) continue;
      ll now = 0;
      if (s == 1 && t == 0) {
        now = (a + (s == 0) + (t == 0));
      }
      elif (s == 0 && t == 1) { now = b + (t == 0); }
      elif (s == 1 && t == 1) {
        now = (a + (s == 0) + (t == 0));
        assert(now == b + (t == 0));
      }
      // o
      if (c == now) {
        newdp[t][1] += dp[s][t];
      }
      // x
      if (t != 0) newdp[t][0] += dp[s][t];
    }
    swap(dp, newdp);
  }
  mint ANS = 0;
  FOR(a, 2) FOR(b, 2) ANS += dp[a][b];
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}