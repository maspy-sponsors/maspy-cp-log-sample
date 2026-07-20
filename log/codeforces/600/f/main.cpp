#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/bipartite_edge_coloring.hpp"

void solve() {
  LL(L, R, M);
  Graph<bool, 0> G(L + R);
  FOR(M) {
    LL(a, b);
    --a, --b;
    G.add(a, L + b);
  }
  G.build();

  auto [C, col] = bipartite_edge_coloring(G);
  print(C);
  for (auto&& x : col) ++x;
  print(col);
}

signed main() {
  solve();
  return 0;
}