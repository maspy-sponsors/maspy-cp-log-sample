#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  VEC(ll, B, N);
  ll a = SUM<ll>(A);
  ll b = SUM<ll>(B);

  if (A == B) return print(0);
  if (b == N) return print(-1);
  if (a == 0) return print(-1);

  vv(ll, C, 2, 2);
  FOR(i, N) C[A[i]][B[i]]++;

  ll x01 = C[0][1];
  ll x10 = C[1][0];
  if (x10 % 2 == 1) {
    return print(1);
  }
  if (x10 > 0) {
    return print(2);
  }
  assert(x10 == 0);
  print(2);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}