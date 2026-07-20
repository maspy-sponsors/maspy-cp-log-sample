#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  vi B = cumsum<ll>(A);
  ll ANS = infty<ll>;
  FOR(n, 1, N) {
    ll a = B[n];
    ll b = B[N] - B[n];
    chmin(ANS, abs(a - b));
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}