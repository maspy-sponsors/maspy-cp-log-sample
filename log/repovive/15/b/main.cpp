#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  VEC(ll, A, 3);
  ll S = SUM<ll>(A);
  if (S % 2 == 1) return No();
  ll T = S / 2;
  vi X = A, Y = A;
  FOR(i, 3) {
    ll x = min(A[i], T);
    T -= x;
    X[i] = x;
    Y[i] = A[i] - x;
  }
  Yes();
  print(X, Y);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}