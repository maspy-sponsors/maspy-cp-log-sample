#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

/*
偶数方向、奇数方向で独立に解くことになる

[x^H] of
((x+x^-1)(y+y^{-1})(xy+x^{-1}y^{-1})-2)^n

[x^H] of
(x+x^-1)(y+y^{-1})(xy+x^{-1}y^{-1})^n
まだ2乗？たたみこみになってるかも
*/

vc<mint> sub(ll N, ll H) {
  H = abs(H);
  vc<mint> F(N + 1);

  // FOR(n, N + 1) {
  //   FOR(b, n + 1) {
  //     ll a = b + H;
  //     F[n] += C<mint>(n, b + H) * C<mint>(n, b) * C<mint>(n, b);
  //   }
  // }
  vc<mint> A(N + 1), B(N + 1);
  FOR(i, N + 1)
  A[i] = fact_inv<mint>(i) * fact_inv<mint>(i) * fact_inv<mint>(i + H);
  FOR(i, H, N + 1) {
    B[i] = fact_inv<mint>(i) * fact_inv<mint>(i) * fact_inv<mint>(i - H);
  }
  F = convolution<mint>(A, B);
  FOR(n, N + 1) F[n] *= fact<mint>(n).pow(3);

  //
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  FOR(i, N + 1) A[i] = fact_inv<mint>(i) * mint(-2).pow(i);
  vc<mint> G = convolution(F, A);
  FOR(i, N + 1) G[i] *= fact<mint>(i);

  // vc<mint> G(N + 1);

  // FOR(n, N + 1) {
  //   FOR(i, n + 1) { G[n] += F[i] * mint(-2).pow(n - i) * C<mint>(n, i); }
  // }
  SHOW(G);
  return G;
}

void solve() {
  LL(N, H, W);
  vc<mint> F = sub(N, H);
  vc<mint> G = sub(N, W);
  SHOW(F);
  SHOW(G);
  FOR(i, N + 1) F[i] *= fact_inv<mint>(i);
  FOR(i, N + 1) G[i] *= fact_inv<mint>(i);
  F = convolution<mint>(F, G);
  F.resize(N + 1);
  FOR(i, N + 1) F[i] *= fact<mint>(i);
  print(F[N]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}