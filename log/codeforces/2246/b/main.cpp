#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  if (N == 1) return print(1);
  if (N == 2) return print(-1);
  vi B;
  B.eb(1);
  while (len(B) < N - 1) {
    ll a = POP(B);
    B.eb(2 * a);
    B.eb(2 * a);
  }

  ll x = POP(B);
  B.eb(x / 2 * 3);
  B.eb(x * 3);

  ll LCM = 1;
  for (auto &x : B) LCM = LCM / gcd(LCM, x) * x;

  for (auto &x : B) x = LCM / x;
  SHOW(MAX(B) <= TEN[17]);
  print(B);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}