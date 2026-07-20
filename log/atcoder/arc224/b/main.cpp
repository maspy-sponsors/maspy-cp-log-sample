#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  ll ANS = 0;
  auto f = [&](ll n) -> ll {
    if (!(1 <= n && n <= N)) return 0;
    ll m = ceil<ll>(N, n);
    ll k = n + m - 1;
    ll ans = k;
    ans += 2 * (N - k);
    --ans;
    return ans;
  };
  ll A = sqrtl(N);
  FOR(d, A - 10, A + 11) chmax(ANS, f(d));
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}
