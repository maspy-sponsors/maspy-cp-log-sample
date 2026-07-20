#include "my_template.hpp"
#include "other/io.hpp"
#include "random/base.hpp"
#include "nt/divisors.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);

  FOR(50) {
    int i, j;
    while (1) {
      i = RNG(0, N);
      j = RNG(0, N);
      if (i == j) continue;
      break;
    }
    ll diff = abs(A[i] - A[j]);
    auto div = divisors(diff);

    for (auto &&d : div) {
      if (d <= 2) continue;
      vi B(N);
      FOR(i, N) B[i] = A[i] % d;
      sort(all(B));
      auto key = B;
      UNIQUE(key);
      for (auto &&k : key) {
        ll cnt = UB(B, k) - LB(B, k);
        if (cnt > N - cnt) {
          return print(d);
        }
      }
    }
  }
  print(-1);
}

signed main() {
  solve();
  return 0;
}
