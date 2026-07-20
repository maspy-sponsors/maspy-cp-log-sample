#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  print(SUM<ll>(A));
}

signed main() {
  solve();
  return 0;
}
