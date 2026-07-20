#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/count/count_connected_subgraph.hpp"
#include "graph/count/count_tree_subgraph.hpp"
#include "graph/count/count_biconnected_subgraph.hpp"

using mint = modint998;

/*
あー
連結とはいってないので
*/

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  auto conn = count_connected_subgraph<mint, 16>(G);
  SHOW(conn);
  {
    auto tree = count_tree_subgraph<mint, 16>(G);
    SHOW(tree);
  }

  // 0,N-1 が同じ成分に来ることを禁止
  auto dp = count_biconnected_subgraph<mint, 16>(G);
  FOR(v, N) dp[1 << v] = 0;
  FOR(s, 1 << N) {
    if (has_kth_bit(s, 0) && has_kth_bit(s, N - 1) && popcnt(s) >= 3) dp[s] = 0;
  }

  // biconnected
  SHOW(dp);

  FOR(r, N) {
    // r may be art -> r is not art
    vc<mint> f(1 << (N - 1));
    FOR(L, 1 << r)
    FOR(R, 1 << (N - 1 - r)) f[L | R << r] = dp[L | (R << (1 + r)) | (1 << r)];
    f = sps_exp<mint, 15>(f);
    FOR(L, 1 << r)
    FOR(R, 1 << (N - 1 - r)) dp[L | (R << (1 + r)) | (1 << r)] = f[L | R << r];
    SHOW(r, dp);
  }

  dp = sps_exp<mint, 16>(dp);
  mint ANS = mint(2).pow(M) - dp.back();
  SHOW(dp);
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}