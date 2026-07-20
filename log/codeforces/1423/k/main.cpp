#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/primetable.hpp"

void solve() {
  auto primes = primetable(1 << 20);
  vc<int> A(1 << 20);
  for (auto &&p : primes) A[p] = 1;
  A = cumsum<int>(A);

  INT(T);
  FOR(T) {
    LL(N);
    ll lo = sqrt(N);
    while (lo * lo <= N) ++lo;
    ll hi = N;
    ll k = A[hi + 1] - A[lo];
    print(1 + k);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}