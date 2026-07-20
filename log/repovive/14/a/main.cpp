#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, K);
  if (N == K) {
    ll S = N * (N + 1) / 2;
    return Yes(S % 2 == 1);
  }
  Yes();
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}