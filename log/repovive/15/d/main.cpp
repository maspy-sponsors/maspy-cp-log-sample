#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);

  if (SUM<ll>(A) != 0) return print(-1);
  vc<pi> X, Y;
  FOR(i, N) if (A[i] > 0) X.eb(i, A[i]);
  FOR(i, N) if (A[i] < 0) Y.eb(i, -A[i]);

  ll ANS = N - 1;
  while (len(X)) {
    auto [i, a] = POP(X);
    auto [j, b] = POP(Y);
    if (i > j) return print(-1);
    chmin(ANS, j - i);
    ll c = min(a, b);
    a -= c, b -= c;
    if (a > 0) X.eb(i, a);
    if (b > 0) Y.eb(j, b);
  }
  print(ANS);
}

signed main() {
  solve();
  return 0;
}