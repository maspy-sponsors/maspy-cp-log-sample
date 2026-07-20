#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_pow.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, S);
  vc<mint> f(M + 1, 1);
  f.resize(S + 1);
  f = fps_pow<mint>(f, N);
  print(f[S]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}