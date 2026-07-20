#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "graph/tree.hpp"

using mint = modint998;

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();
  Tree<decltype(G)> tree(G);

  auto P = tree.restore_path(0, N - 1);

  ll d = len(P) - 1;
  SHOW(d);

  if (d % 2 == 0) {
    mint ANS = 1;
    FOR(i, d / 2) {
      ll a = P[i], b = P[d - i];
      mint ok = N - tree.subtree_size(a, b) - tree.subtree_size(b, a);
      ANS *= ok;
    }
    print(ANS);
    return;
  }

  ll n = d / 2;
  map<pi, mint> dp;
  dp[mp(0, N - 1)] = 1;

  FOR(step, d / 2 + 1) {
    map<pi, mint> newdp;
    for (auto& [k, x] : dp) {
      auto [a, b] = k;
      if (tree.dist(a, b) >= d - 2 * step + 2) continue;
      SHOW(step, a, b, x);
      mint ok = N - tree.subtree_size(a, b) - tree.subtree_size(b, a);
      int a1 = tree.jump(a, b, 1);
      int b1 = tree.jump(b, a, 1);
      newdp[mp(a1, b1)] += x * ok;
      newdp[mp(a, b1)] += x;
      newdp[mp(a1, b)] += x;
    }
    swap(dp, newdp);
  }

  mint ANS = 0;
  for (auto& [k, x] : dp) {
    auto [a, b] = k;
    SHOW(a, b, x);
    if (a == b) ANS += x;
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}