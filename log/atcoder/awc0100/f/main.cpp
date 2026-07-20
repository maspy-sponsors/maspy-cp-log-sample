#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, K);
  VEC(ll, A, N);

  auto Ac = cumsum<ll>(A);

  ll ANS = 0;
  FOR(L, N) {
    auto check = [&](ll R) -> bool { return Ac[R] - Ac[L] >= K; };
    ll R = binary_search(check, N + 1, L, 0);
    ANS += N - R + 1;
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}