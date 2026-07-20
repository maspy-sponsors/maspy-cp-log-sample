#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/ds/lazy_tree_monoid.hpp"
#include "alg/acted_monoid/min_add.hpp"

void solve() {
  LL(N);

  vi W(N - 1);
  Graph<int, 1> G(N);
  FOR(i, N - 1) {
    int v = 1 + i;
    int p;
    read(p);
    --p;
    G.add(p, v);
    read(W[i]);
  }

  G.build();
  Tree<decltype(G)> tree(G);

  Lazy_Tree_Monoid<decltype(tree), ActedMonoid_Min_Add<ll>, 1> TM(tree, W);

  LL(Q);
  FOR(Q) {
    INT(a, b);
    --a, --b;
    TM.apply_path(a, b, 1);
  }

  LL(R);
  FOR(R) {
    INT(a, b);
    --a, --b;
    ll ANS = 0;
    if (a != b) ANS = TM.prod_path(a, b);
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}