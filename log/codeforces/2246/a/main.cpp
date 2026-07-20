#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  vi A(N);
  int p = 2;
  FOR(i, N) {
    if (i % 2 == 0) A[i] = p, p += 2;
  }
  p = 1;
  FOR(i, N) {
    if (i % 2 == 1) A[i] = p, p += 2;
  }
  print(A);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
