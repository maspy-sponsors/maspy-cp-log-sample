#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/multipoint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, K);
  vc<mint> f(N + 1);
  FOR(n, N + 1) {
    if (N - n > K) continue;
    f[n] = fact_inv<mint>(N - n) * fact_inv<mint>(n);
  }
  vc<mint> X(M + 1);
  FOR(i, M + 1) X[i] = i;
  vc<mint> Y = multipoint_eval<mint>(f, X);

  FOR(m, 1, M + 1) {
    mint ans = Y[m];
    // ans *= fact_inv<mint>(m);
    ans *= fact<mint>(N);
    print(ans);
  }
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}