#include "my_template.hpp"
#include "other/io.hpp"

#define PI 3.14159265359
using ld = long double;

void solve() {
  LL(x1, y1, r1, x2, y2, r2);
  ll dx = x1 - x2, dy = y1 - y2;
  if (dx * dx + dy * dy >= (r1 + r2) * (r1 + r2)) {
    print(0);
    return;
  }
  if (dx * dx + dy * dy <= (r1 - r2) * (r1 - r2)) {
    ld r = min(r1, r2);
    print(PI * r * r);
    return;
  }

  ld d = sqrt(dx * dx + dy * dy);

  ld cos_1 = (r1 * r1 + dx * dx + dy * dy - r2 * r2) / (2 * d * r1);
  ld cos_2 = (r2 * r2 + dx * dx + dy * dy - r1 * r1) / (2 * d * r2);
  ld theta_1 = acos(cos_1);
  ld theta_2 = acos(cos_2);
  ld ans = r1 * r1 * (theta_1 - sin(2 * theta_1) / 2);
  ans += r2 * r2 * (theta_2 - sin(2 * theta_2) / 2);
  print(ans);
}

signed main() {
  solve();

  return 0;
}