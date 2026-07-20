#include "my_template.hpp"
#include "other/io.hpp"

/*

*/

void solve() {
  LL(N);
  auto [a, b] = divmod<ll>(N, 9);
  // 9a + b
  /*
  9+9+...+9+b
  */

  if (b == 0) {
    ll L = 9 * TEN[17];
    ll R = L + a - 1;
    return print(L, R);
  }
  ll R = b * TEN[17];
  ll L = R - a;
  print(L, R);
}

signed main() {
  INT(T);
  FOR(T) solve();
}
