#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  FOR(N) {
    LL(a, b);
    STR(S);
    if (S == "keep") {
      ANS += b - a;
    } else {
    }
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}