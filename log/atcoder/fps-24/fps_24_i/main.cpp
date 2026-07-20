#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution_all.hpp"

using mint = modint998;

void solve() {
  LL(N, K);
  vvc<mint> polys;
  FOR(N) {
    LL(a);
    vc<mint> f = {1, a};
    polys.eb(f);
  }
  vc<mint> f = convolution_all(polys);
  print(f[K]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}