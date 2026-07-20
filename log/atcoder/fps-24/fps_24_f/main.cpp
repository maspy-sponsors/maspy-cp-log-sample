#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/interpolate_linear_rec.hpp"

using mint = modint998;

void solve() {
  LL(N);
  ll LIM = 100;
  vv(mint, dp, 2, 2);
  dp[0][0] = 1;
  vc<mint> S;
  FOR(LIM) {
    S.eb(dp[1][0]);
    vv(mint, newdp, 2, 2);
    FOR(a, 2) FOR(b, 2) {
      newdp[a][b] += dp[a][b];
      newdp[a][1 - b] += dp[a][b];
      newdp[1 - a][b] += dp[a][b];
    }
    swap(dp, newdp);
  }
  mint ANS = interpolate_linear_rec<mint>(S, N, 0);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}