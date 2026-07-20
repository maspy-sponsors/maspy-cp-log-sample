#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  vi EV, OD;
  FOR(N) {
    LL(x);
    if (x % 2 == 0)
      EV.eb(x);
    else
      OD.eb(x);
  }

  sort(all(EV));
  sort(all(OD));
  reverse(all(EV));
  reverse(all(OD));

  ll ANS = -1;

  if (len(EV) >= 2) {
    chmax(ANS, EV[0] + EV[1]);
  }
  if (len(OD) >= 2) {
    chmax(ANS, OD[0] + OD[1]);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
