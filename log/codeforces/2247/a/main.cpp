#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll a = 0, b = 0;
  FOR(i, N) { (A[i] == 1 ? a : b)++; }

  SHOW(a, b);
  ll d = abs(a - b);
  YES(d % 4 == 0);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}