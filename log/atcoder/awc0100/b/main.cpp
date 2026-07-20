#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  ll ma = -1;
  ll ANS = -1;
  FOR(i, N) {
    LL(a, b);
    if (chmax(ma, a + b)) ANS = 1 + i;
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}