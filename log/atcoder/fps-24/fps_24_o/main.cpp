#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "nt/primetable.hpp"
#include "poly/compositional_inverse.hpp"

using mint = modint998;

void solve() {
  LL(N);
  auto primes = primetable(N);
  vc<mint> f(N + 1);
  f[0] = 1;
  for (auto& p : primes) f[p] = fact_inv<mint>(p);
  // x/f(x)
  f = fps_inv<mint>(f);
  f.insert(f.begin(), 0);

  f = compositional_inverse<mint>(f);
  FOR(i, N + 1) f[i] *= fact<mint>(i);
  SHOW(f);
  print(f[N] * inv<mint>(N));
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}