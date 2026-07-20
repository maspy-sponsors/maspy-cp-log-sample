#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/base.hpp"

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);

  // 辺に 1 を割り当てておく
  vi A(N);
  vi F(N);
  vi E(M, 1);
  for (auto& e : G.edges) {
    F[e.frm]++, F[e.to]++;
  }

  FOR(v, 1, N) {
    //
    vc<pi> X, Y;
    set<int> S;
    for (auto& e : G[v]) {
      if (e.to > v) continue;
      (A[e.to] == 0 ? X : Y).eb(e.to, e.id);
      S.insert(F[e.to]);
    }

    // これまでのを保ったまま辺重みを増減させる
    /*
    X, -1: [0] 1 v -> [1] 0 v
    Y, +1: [1] 1 v -> [0] 2 v
    */
    ll base = F[v] - len(X);
    ll k = 0;
    while (S.count(base + k)) ++k;
    assert(k <= len(X) + len(Y));

    ll k1 = min(k, len(X));
    ll k2 = k - k1;
    assert(0 <= k1 && k1 <= len(X));
    assert(0 <= k2 && k2 <= len(Y));
    k1 = len(X) - k1;

    // k1: -1
    // k2: +1
    assert(!S.count(F[v] + k2 - k1));

    FOR(i, k1) {
      auto [u, eid] = X[i];
      A[u] = 1;
      E[eid] = 0;
      F[v]--;
    }
    FOR(i, k2) {
      auto [u, eid] = Y[i];
      A[u] = 0;
      E[eid] = 2;
      F[v]++;
    }
  }

  vi out;
  FOR(v, N) if (A[v] == 1) out.eb(1 + v);
  print(len(out));
  print(out);

  FOR(i, M) {
    int a = G.edges[i].frm;
    int b = G.edges[i].to;
    print(1 + a, 1 + b, E[i]);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}