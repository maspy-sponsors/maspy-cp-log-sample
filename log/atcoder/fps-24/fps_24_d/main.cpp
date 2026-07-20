#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  M -= N - 1;
  if (M < 0) return print(0);
  vc<mint> f = {1, 0, -1};
  f.resize(M + 1);
  f = fps_pow_1<mint>(f, -(N - 1));
  f = cumsum<mint>(f, 0);
  f = cumsum<mint>(f, 0);
  print(f[M] * fact<mint>(N));
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}