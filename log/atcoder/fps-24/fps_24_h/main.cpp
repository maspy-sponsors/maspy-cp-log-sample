#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

void solve() {
  LL(N, M);
  ll K = N + M;
  vc<mint> B(K + 1);
  FOR(k, K + 1) { B[k] = C<mint>(k, N) * C_negative<mint>(k, M); }
  SHOW(C<mint>(3, N), C_negative<mint>(3, M));
  SHOW(B);
  FOR(n, K + 1) B[n] *= fact_inv<mint>(n);
  vc<mint> F(K + 1);
  FOR(k, K + 1) { F[k] = fact_inv<mint>(k) * mint(-1).pow(k); }
  vc<mint> A = convolution<mint>(B, F);
  A.resize(K + 1);
  FOR(k, K + 1) A[k] *= fact<mint>(k);
  mint ANS = SUM<mint>(A);
  SHOW(A);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}
