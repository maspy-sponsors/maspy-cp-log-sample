#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(X, Y);
  ll Z = X + X;
  while (Z < Y) {
    if (Y % Z != 0) return YES();
    Z += X;
  }
  NO();
}

signed main() {
  INT(T);
  FOR(T) solve();
}