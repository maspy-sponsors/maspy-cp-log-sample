#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"

/*
wow
「ちょうど」ひとつとのこと
*/

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  vc<int> A(N, -1);

  auto dfs = [&](auto& dfs, int v, int p, int d) -> void {
    A[v] = d;
    for (auto& e : G[v]) {
      if (A[e.to] != -1) continue;
      dfs(dfs, e.to, v, d + 1);
    }
  };
  dfs(dfs, 0, -1, 0);
  print(A);
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}