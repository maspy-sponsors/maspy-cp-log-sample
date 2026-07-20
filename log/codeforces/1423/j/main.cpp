#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint107;

void solve() {
  LL(N);

  using ARR = array<mint, 8>;

  auto dfs = [&](auto& dfs, ll N) -> ARR {
    if (N == 0) {
      return {mint(1), mint(0), mint(0), mint(0),
              mint(0), mint(0), mint(0), mint(0)};
    }

    ARR A;
    fill(all(A), mint(0));
    ll M = N / 2;
    ARR B = dfs(dfs, M);
    FOR(x, 8) {
      int y0 = (N + x) & 1;
      int k = M - (N - x - y0) / 2;
      A[x] = B[k] + B[k + 1] + B[k + 2] + B[k + 3];
    }
    return A;
  };
  print(dfs(dfs, N)[0]);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}