#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  vi A(M), B(M);
  FOR(i, M) read(A[i], B[i]);
  for (auto& x : A) --x;
  ll S = SUM<ll>(B);
  if (S > N) return print(-1);
  if (S < N) return print(1);
  ll x = 0;
  FOR(i, M) x += A[i] * B[i];
  x -= N * (N - 1) / 2;
  x = (x % N == 0 ? 1 : -1);
  print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}