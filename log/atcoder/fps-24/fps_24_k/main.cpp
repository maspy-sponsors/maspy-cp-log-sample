#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/famous/indecomposable_permutations.hpp"

using mint = modint998;

void solve() {
  LL(N);
  vc<mint> ANS = indecomposable_permutations<mint>(N);
  print(ANS[N]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}
