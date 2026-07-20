#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  sort(all(A));
  vi ANS;
  FOR(Q) {
    LL(x);
    ll ans = upper_bound(all(A), x) - A.begin();
    ANS.eb(ans);
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}