#include "my_template.hpp"
#include "other/io.hpp"
#include "other/mex.hpp"

void solve() {
  LL(N, M);
  vc<set<int>> G(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    G[a].emplace(b);
    G[b].emplace(a);
  }

  vc<set<int>> G0 = G;

  vc<int> V;
  vc<int> que;
  FOR(v, N) que.eb(v);
  vc<int> exist(N, 1);

  while (len(que)) {
    int v = POP(que);
    if (!exist[v]) continue;
    if (len(G[v]) >= 4) continue;
    V.eb(v);
    for (int w : G[v]) {
      G[w].erase(v);
      que.eb(w);
    }
    G[v].clear();
    exist[v] = 0;
  }

  SHOW(exist);
  SHOW(V);
  reverse(all(V));

  vi A(N, -1);
  for (auto &v : V) {
    vc<int> X;
    for (auto &w : G0[v]) {
      if (A[w] == -1) continue;
      X.eb(A[w]);
    }
    A[v] = mex(X);
  }
  for (auto &x : A) ++x;

  Yes();
  print(A);
}

signed main() { solve(); }
