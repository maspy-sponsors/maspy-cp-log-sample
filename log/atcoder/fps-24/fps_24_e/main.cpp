#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/convolution_all.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  vvc<mint> polys;
  FOR(m, 1, M + 1) {
    vc<mint> f(m + 1);
    FOR(i, m + 1) f[i] = fact_inv<mint>(i);
    polys.eb(f);
  }
  vc<mint> f = convolution_all<mint>(polys);
  f.resize(N + 1);
  mint ANS = f[N] * fact<mint>(N);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}