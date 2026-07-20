#include "my_template.hpp"
#include "other/io.hpp"

#include "convex/slope_trick/slope_trick_0.hpp"

void solve() {
  LL(N);
  Slope_Trick_0 X;

  FOR(i, N) {
    LL(a);
    a -= i;
    X.add_abs(a);
    X.clear_right();
  }
  print(X.min_f);
}

signed main() {
  solve();
  return 0;
}