#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  vi B = A;
  UNIQUE(B);
  for (auto &x : A) x = LB(B, x);
  vi F(N);
  FOR(i, N) F[A[i]]++;
  auto Fc = cumsum<ll>(F);

  vi ANS;
  for (auto &a : A) ANS.eb(Fc.back() - Fc[a + 1]);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}