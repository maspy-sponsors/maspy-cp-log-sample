#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, c);
  VEC(ll, A, N);
  for (auto &x : A) x -= c;
  sort(all(A));

  ll n = ceil<ll>(N, 2);
  ll ANS = 0;
  FOR(n) { ANS += POP(A); }
  for (auto &x : A)
    if (x > 0) ANS += x;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}