#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/composition.hpp"

using mint = modint998;

void solve() {
  LL(N);
  --N;
  VEC(mint, F, N + 1);
  vc<mint> ANS(N + 1);
  ANS[1] = 1;

  ll e = (998244353 + 1) / 2;
  while (e) {
    if (e & 1) ANS = composition(ANS, F);
    F = composition(F, F);
    e /= 2;
  }

  print(ANS);
}

int main() { solve(); }