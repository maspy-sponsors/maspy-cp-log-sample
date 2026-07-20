#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);

  auto check = [&](ll k) -> bool {
    if (N <= k) return 1;
    ll x = N - k, y = N - k;
    return x + y <= k;
  };
  ll ANS = binary_search(check, N + 100, 0);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}