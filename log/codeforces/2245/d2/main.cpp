#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "graph/strongly_connected_component.hpp"

void solve() {
  LL(N, M);
  vc<tuple<int, int, int>> cond;
  FOR(M) {
    INT(t, i, j);
    --t, --i, --j;
    cond.eb(t, i, j);
  }

  Graph<int, 1> G(N + N);
  for (auto [t, i, j] : cond) {
    SHOW(t, i, j);
    FOR(2) {
      swap(i, j);
      if (t == 0) {
        G.add(2 * i + 0, 2 * j + 1, 0);
      } else {
        G.add(2 * i + 1, 2 * j + 0, -1);
      }
    }
  }
  G.build();

  auto [nc, comp] = strongly_connected_component(G);

  SHOW(nc, comp);
  for (auto& e : G.edges) {
    if (e.cost == -1 && comp[e.frm] == comp[e.to]) return NO();
  }

  // OK
  Graph<int, 1> H(nc);
  for (auto& e : G.edges) {
    int a = e.frm, b = e.to;
    a = comp[a], b = comp[b];
    SHOW(nc, a, b, e.cost);
    if (a == b) continue;
    H.add(a, b, e.cost);
  }
  H.build();
  H.debug();
  vi dp(nc, infty<int>);
  FOR(i, nc) {
    if (dp[i] == infty<int>) {
      dp[i] = 0;
    }
    for (auto& e : H[i]) {
      chmin(dp[e.to], dp[i] + e.cost);
    }
  }
  SHOW(dp);

  vi A(N);
  FOR(i, N) {
    A[i] += dp[comp[2 * i + 0]];
    A[i] -= dp[comp[2 * i + 1]];
  }
  SHOW(A);

  for (auto& [t, i, j] : cond) {
    if (t == 0) {
      assert(A[i] + A[j] >= 0);
    } else {
      assert(A[i] + A[j] < 0);
    }
  }
  YES();
  print(A);
}

signed main() {
  INT(T);
  FOR(T) solve();
}  // END: main.cpp