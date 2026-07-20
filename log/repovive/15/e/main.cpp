#include "my_template.hpp"
#include "other/io.hpp"

#include "seq/inversion.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  VEC(ll, B, N);

  vi S;
  auto I = argsort(A);
  FOR(2) {
    reverse(all(I));
    vi X = rearrange(A, I);
    vi Y = rearrange(B, I);
    ll x = inversion(X);
    ll y = inversion(Y);
    S.eb(x + y);
  }

  ll ANS = (MAX(S) - MIN(S)) / 2 + 1;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}