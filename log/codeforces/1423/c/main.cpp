#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N, K);
  Graph<int, 0> G(N);
  G.read_tree();
  vc<pair<int, int>> ANS;

  vc<int> V(N);
  FOR(i, N) V[i] = 1 + i;

  auto F = [&](auto& F, Graph<int, 0>& G, vc<int>& V) -> void {
    ll N = G.N;
    G.debug();
    vc<int> root;
    vvc<int> es;
    vc<int> color(N, -1);
    vc<int> par(N, -1);

    ll S = sqrtl(N);

    auto add_ANS = [&](int a, int b) -> void {
      if (a == b) return;
      a = V[a], b = V[b];
      ANS.eb(a, b);
    };

    if (N <= 5) {
      FOR(j, N) FOR(i, j) add_ANS(i, j);
      return;
    }

    auto find_component = [&](int v, vc<int>& E) -> void {
      int c = len(root);
      root.eb(v);
      es.eb(E);
      for (auto& v : E) color[v] = c;
    };

    auto dfs = [&](auto& dfs, int v, int p) -> vc<int> {
      par[v] = p;
      vc<int> E;
      for (auto& e : G[v]) {
        if (e.to == p) continue;
        vc<int> F = dfs(dfs, e.to, v);
        if (len(E) < len(F)) swap(E, F);
        F.eb(e.to);
        concat(E, F);
        if (len(E) >= S) {
          find_component(v, E);
          E.clear();
        }
      }
      return E;
    };
    vc<int> E = dfs(dfs, 0, -1);
    if (!E.empty()) find_component(0, E);

    // betw root
    for (auto& a : root) {
      for (auto& b : root) {
        if (a < b) add_ANS(a, b);
      }
    }

    //
    FOR(v, 1, N) { add_ANS(v, root[color[v]]); }

    for (int v : root) {
      int c = color[v];
      if (c == -1) continue;
      for (auto& w : es[c]) {
        add_ANS(v, w);
      }
    }

    FOR(c, len(root)) {
      vc<int> S;
      for (int v : es[c]) {
        S.eb(v), S.eb(par[v]);
      }
      UNIQUE(S);
      Graph<int, 0> H = G.rearrange(S);
      vc<int> newV = rearrange(V, S);
      F(F, H, newV);
    }
  };
  F(F, G, V);

  for (auto& [a, b] : ANS)
    if (a > b) swap(a, b);
  UNIQUE(ANS);

  print(len(ANS));
  for (auto& [a, b] : ANS) print(a, b);
}

signed main() {
  solve();
  return 0;
}