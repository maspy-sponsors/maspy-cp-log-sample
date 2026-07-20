#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "mod/modint.hpp"
#include "poly/fps_div.hpp"

using mint = modint998;

void solve() {
  LL(N, M, K);
  VEC(ll, A, N);
  VEC(ll, B, M);
  auto toS = [&](vi A) -> vc<mint> {
    // 1/(1-ax) を全部足す
    auto dfs = [&](auto& dfs, int L, int R) -> pair<vc<mint>, vc<mint>> {
      if (R == L + 1) {
        vc<mint> f = {1};
        vc<mint> g = {1, -A[L]};
        return {f, g};
      }
      int M = (L + R) / 2;
      auto [A1, B1] = dfs(dfs, L, M);
      auto [A2, B2] = dfs(dfs, M, R);
      vc<mint> X = convolution<mint>(A1, B2);
      vc<mint> Y = convolution<mint>(A2, B1);
      vc<mint> Z = convolution<mint>(B1, B2);
      FOR(i, len(Y)) X[i] += Y[i];
      return {X, Z};
    };
    auto [f, g] = dfs(dfs, 0, len(A));
    f.resize(K + 1);
    g.resize(K + 1);
    SHOW(A, f, g);
    return fps_div(f, g);
  };
  vc<mint> SA = toS(A);
  vc<mint> SB = toS(B);
  SHOW(SA);
  SHOW(SB);

  FOR(i, K + 1) SA[i] *= fact_inv<mint>(i);
  FOR(i, K + 1) SB[i] *= fact_inv<mint>(i);

  vc<mint> S = convolution<mint>(SA, SB);
  FOR(i, len(S)) S[i] *= fact<mint>(i);

  mint c = mint(1) / mint(N * M);
  for (auto& x : S) x *= c;

  FOR(k, 1, K + 1) print(S[k]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}