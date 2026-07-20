#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/tree.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);

  Graph<int, 0> G(N);
  FOR(N - 1) {
    LL(a, b);
    G.add(--a, --b);
  }
  G.build();
  Tree<decltype(G)> tree(G);

  struct T {
    ll ans = 0;
    int max_cnt = 0;
    map<int, ll> CNT;
  };

  using node_data = T;
  using edge_data = T;
  // 辺属性の単位元
  auto e_unit = [&]() -> edge_data { return T(); };

  // 辺属性を頂点属性に変換
  auto f_ev = [&](int v, edge_data* x) -> node_data* {
    auto k = A[v];
    if (x->CNT.count(k))
      ++x->CNT[k];
    else
      x->CNT[k] = 1;
    if (x->CNT[k] == x->max_cnt) {
      x->ans += k;
    }
    elif (x->CNT[k] > x->max_cnt) {
      x->max_cnt = x->CNT[k];
      x->ans = k;
    }
    return x;
  };
  // 頂点属性を辺属性に変換
  auto f_ve = [&](int v, node_data* x) -> edge_data* { return x; };

  // 辺属性のマージ
  auto mul_e = [&](edge_data* x, edge_data* y) -> edge_data* {
    if (x->CNT.size() < y->CNT.size()) swap(x, y);
    for (auto it = y->CNT.begin(); it != y->CNT.end(); ++it) {
      ll k, cnt;
      tie(k, cnt) = *it;
      if (x->CNT.count(k))
        x->CNT[k] += cnt;
      else
        x->CNT[k] = cnt;
      if (x->CNT[k] == x->max_cnt) {
        x->ans += (ll)k;
      }
      elif (x->CNT[k] > x->max_cnt) {
        x->max_cnt = x->CNT[k];
        x->ans = (ll)k;
      }
    }
    return x;
  };
  vi ANS(N);

  auto tree_dp = [&]() {
    vc<node_data*> dp1_v(N, nullptr);
    vc<edge_data*> dp1_e(N, nullptr);
    FOR_R(i, N) {
      int v = tree.V[i];
      edge_data* x = new edge_data;
      *x = e_unit();
      for (auto&& e : G[v]) {
        auto w = e.to;
        if (tree.parent[w] == v) {
          x = mul_e(x, dp1_e[w]);
        }
      }
      dp1_v[v] = f_ev(v, x);
      ANS[v] = dp1_v[v]->ans;
      dp1_e[v] = f_ve(v, dp1_v[v]);
    }

    return mp(dp1_v, dp1_e);
  };
  auto [dp1_v, dp1_e] = tree_dp();
  print(ANS);
}

signed main() {
  solve();

  return 0;
}