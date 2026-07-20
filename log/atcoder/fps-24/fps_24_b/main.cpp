#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/coef_of_rational_fps.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vc<mint> f = {1, 2, 2, 1};
  vc<mint> g = {1, 0, -1, -1, 0, 1};
  mint ANS = coef_of_rational_fps<mint>(f, g, N);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}