#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(X, Y, L, R, A, B);
  vi F(24, Y);
  FOR(i, L, R) F[i] = X;

  ll ANS = 0;
  FOR(i, A, B) ANS += F[i];
  print(ANS);
}

signed main() {
  solve();
  return 0;
}
