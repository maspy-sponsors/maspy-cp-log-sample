#include "my_template.hpp"
#include "other/io.hpp"
#include "flow/bipartite.hpp"

void solve() {
  INT(N, M);
  using T = tuple<int, int, int>;
  vc<T> edge;
  FOR(M) {
    INT(a, b, c);
    --a, --b;
    edge.eb(c, a, b + N);
  }

  sort(all(edge));
  vc<int> color(N + N);
  FOR(i, N, N + N) color[i] = 1;

  auto check = [&](int m) -> bool {
    if (m > M) return 1;
    Graph<int, 0> G(N + N);
    FOR(i, m) {
      auto [c, a, b] = edge[i];
      G.add(a, b);
    }
    G.build();
    BipartiteMatching<decltype(G)> BM(G, color);
    int match = len(BM.matching());
    return match == N;
  };

  int ans = binary_search(check, infty<int>, 0);
  if (ans > M) return print(-1);
  ll ANS = 0;
  FOR(i, ans) {
    auto [c, a, b] = edge[i];
    chmax(ANS, c);
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}