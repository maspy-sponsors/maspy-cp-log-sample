#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_exp.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vc<mint> f(N + 1);
  FOR(n, 3, N + 1) { f[n] = inv<mint>(n); }
  f = fps_exp<mint>(f);
  mint ANS = f[N] * fact<mint>(N);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}