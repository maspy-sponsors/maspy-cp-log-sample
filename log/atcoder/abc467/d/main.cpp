#include "my_template.hpp"
#include "other/io.hpp"

#include "geo/perpendicular_bisector.hpp"

using P = Point<i128>;

void solve() {
  P A, B, C, D;
  read(A, B, C, D);

  Line<i128> L1 = perpendicular_bisector<i128>(A, B);
  Line<i128> L2 = perpendicular_bisector<i128>(C, D);

  No(L1.is_parallel(L2) && !L1.is_same(L2));
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}