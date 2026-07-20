#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll a = 0, b = 0;
  FOR(i, N) if (A[i] % 2 == 0)++ a;
  FOR(i, N) if (A[i] % 2 == 1)++ b;
  if (b == N) return print(N - 1);
  print(1 + b);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}