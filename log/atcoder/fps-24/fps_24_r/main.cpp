#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "poly/ntt.hpp"

using mint = modint998;

// たしかに 2^N でした
void solve() {
  LL(N, T, X);
  --X;
  ll mod = 1 << (N + 1);
  mint ANS = 0;
  // FOR(i, T + 1) {
  //   mint x = C<mint>(T, i);
  //   ll p = bmod<ll>(-T + i + i, mod);
  //   if (p == X || p == mod - X) {
  //     SHOW(i, x);
  //     ANS += x;
  //   }
  // }

  //
  vc<mint> F(mod);
  F[1] += 1;
  F[len(F) - 1] += 1;
  SHOW(F);
  ntt(F, false);
  for (auto &x : F) x = x.pow(T);
  ntt(F, true);
  SHOW(F);

  FOR(p, len(F)) {
    if (p == X || p == mod - X) {
      ANS += F[p];
    }
  }

  ANS *= inv<mint>(2).pow(T);
  print(ANS);
}

int main() { solve(); }