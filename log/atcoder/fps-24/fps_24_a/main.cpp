#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/fps_pow.hpp"

using mint = modint998;

void solve() {
  LL(D, N);
  vc<mint> f = {0, 1, 0, 1, 1, 0, 1};
  f.resize(N + 1);
  f = fps_pow<mint>(f, D);
  print(f[N]);
}

int main() { solve(); }