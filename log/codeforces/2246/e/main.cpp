#include "my_template.hpp"
#include "other/io2.hpp"

#include "random/base.hpp"

void solve() {
  print(1);
  LL(y);

  ll a = 0;
  ll b = RNG(0, 1LL << 29) * 2 + 1;

  if (y == 1) {
    print(a, b);
    LL(z);
    ll ANS = (z % 2 == 0 ? 1 : 0);
    if (z == a) ANS = 0;
    if (z == b) ANS = 1;
    return print(ANS);
  }

  if (y == 0) {
    // AND==0
    // v は偶数
    print(a, b);
    LL(z);
    ll ANS = (z % 2 == 0 ? 0 : 1);
    print(ANS);
  } else {
    // OR
    ll k = topbit(y);
    a = 0, b = 1LL << k;
    print(a, b);
    LL(z);
    ll ANS = (has_kth_bit(z, k) ? 0 : 1);
    print(ANS);
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}