#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/blackbox/complement_graph_bfs.hpp"
#include "graph/base.hpp"
#include "ds/splaytree/splaytree_basic.hpp"

/*
必要
長さ 2 のパス
孤立点がない

十分でもある
まず長さ 2 のパスをとったあとで育てられる
*/

void solve() {
  LL(N, M);
  vc<set<int>> G(N);
  Graph<int, 0> GG(N);

  FOR(M) {
    INT(a, b);
    --a, --b;
    G[a].insert(b);
    G[b].insert(a);
    GG.add(a, b);
  }
  GG.build();

  auto out = [&](vc<int> A) -> void {
    assert(len(A) == N);
    vc<int> P = A;
    sort(all(P));
    FOR(i, N) assert(P[i] == i);
    FOR(i, len(A) - 1) {
      int a = A[i], b = A[i + 1];
      assert(!G[a].count(b));
    }
    for (auto& x : A) ++x;
    Yes();
    print(A);
  };

  vi deg(N);
  FOR(i, N) deg[i] = (N - 1) - len(G[i]);

  if (N == 1) {
    return out({0});
  }
  if (MIN(deg) == 0) return No();

  if (N == 2) {
    return out({0, 1});
  }

  if (MAX(deg) <= 1) return No();

  int r = max_element(all(deg)) - deg.begin();
  auto [dist, par] = complement_graph_bfs(GG, r);
  if (MAX(dist) == infty<int>) return No();

  /*
  サイクルになるまでは先頭または末尾を延長できる
  */

  static SplayTree_Basic<int> ST;
  using np = decltype(ST)::np;
  ST.reset();

  vc<int> nbd;
  FOR(v, N) if (v != r && !G[r].count(v)) nbd.eb(v);
  assert(len(nbd) == deg[r]);

  vc<int> vis(N);

  vc<np> nodes(N);
  FOR(i, N) nodes[i] = ST.new_node(i);

  vc<int> init = {nbd[0], r, nbd[1]};
  for (auto& v : init) vis[v] = 1;
  np root = nodes[init[0]];
  root = ST.merge(root, nodes[init[1]]);
  root = ST.merge(root, nodes[init[2]]);

  FOR(v, N) {
    if (vis[v]) continue;
    int s = ST.get(root, 0);
    int t = ST.get(root, root->size - 1);
    // append left?
    if (!G[s].count(v)) {
      root = ST.merge(nodes[v], root);
      vis[v] = 1;
      continue;
    }
    // append right?
    if (!G[t].count(v)) {
      root = ST.merge(root, nodes[v]);
      vis[v] = 1;
      continue;
    }

    vc<int> path;
    path.eb(v);
    while (1) {
      int p = par[path.back()];
      path.eb(p);
      if (vis[p]) break;
    }
    int p = POP(path);
    // p := tail
    ST.splay(nodes[p], 0);
    root = nodes[p];
    int lsize = (root->l ? root->l->size : 0);
    auto [L, R] = ST.split(root, lsize + 1);
    root = ST.merge(R, L);
    assert(ST.get(root, root->size - 1) == p);
    int tail = p;
    while (len(path)) {
      int v = POP(path);
      assert(!G[tail].count(v));
      root = ST.merge(root, nodes[v]);
      tail = v;
      vis[v] = 1;
    }
  }

  vc<int> ANS = ST.get_all(root);
  out(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
