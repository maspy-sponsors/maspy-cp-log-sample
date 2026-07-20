#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"
#include "flow/bipartite.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/path_cycle.hpp"
#include "graph/tree.hpp"

pair<bool, vvc<int>> solve_connected(Graph<int, 0> G, vc<int> S, vc<int> T,
                                     int step) {
  pair<bool, vvc<int>> ng{};
  vv(int, ANS, step + 1, 0);

  int N = G.N;
  if (len(S) != len(T)) return ng;
  if (S.empty()) return {true, ANS};

  auto match = [&](vc<int> S) -> vc<pair<int, int>> {
    Graph<int, 0> H(N);
    for (auto& v : S) {
      for (auto& e : G[v]) H.add(v, e.to);
    }
    H.build();
    BipartiteMatching<decltype(H)> BM(H);
    return BM.matching();
  };

  auto MS = match(S);
  auto MT = match(T);
  if (len(MS) < len(S)) return ng;
  if (len(MT) < len(T)) return ng;

  for (auto& [a, b] : MS) {
    if (a > b) swap(a, b);
  }
  for (auto& [a, b] : MT) {
    if (a > b) swap(a, b);
  }

  {
    Graph<int, 0> H(N);
    vc<pair<int, int>> E;
    concat(E, MS, MT);
    UNIQUE(E);
    for (auto& [a, b] : E) H.add(a, b);
    H.build();
    auto [paths, cycs] = path_cycle(H);

    map<pair<int, int>, pair<int, int>> change;
    for (auto& C : cycs) {
      assert(len(C) % 2 == 0);
      FOR(i, len(C) / 2) {
        int a = C[2 * i], b = C[2 * i + 1], c = C[(2 * i + 2) % len(C)];
        pair<int, int> X = minmax(a, b);
        pair<int, int> Y = minmax(b, c);
        change[X] = Y;
      }
    }

    for (auto& x : MS)
      if (change.count(x)) x = change[x];
    for (auto& x : MT)
      if (change.count(x)) x = change[x];
  }

  {
    Graph<int, 0> H(N);
    vc<pair<int, int>> E;
    concat(E, MS, MT);
    UNIQUE(E);

    UnionFind uf(N);
    for (auto& [a, b] : E) {
      assert(uf.merge(a, b));
    }
    for (auto& e : G.edges) {
      int a = e.frm, b = e.to;
      if (uf[a] != uf[b]) uf.merge(a, b), E.eb(minmax(a, b));
    }
    assert(uf.n_comp == 1);
    Graph<int, 0> T(N);
    for (auto& [a, b] : E) T.add(a, b);
    T.build();
    swap(G, T);
  }

  assert(G.M == G.N - 1);

  // S-other, T-other に戻す

  vc<int> inS(N), inT(N);
  for (auto& v : S) inS[v] = 1;
  for (auto& v : T) inT[v] = 1;
  for (auto& [a, b] : MS)
    if (!inS[a]) swap(a, b);
  for (auto& [a, b] : MT)
    if (!inT[a]) swap(a, b);

  Tree<decltype(G)> tree(G);
  auto dep = [&](pair<int, int> x) -> int {
    return tree.depth[x.fi] + tree.depth[x.se];
  };

  sort(all(MS), [&](auto& a, auto& b) -> bool { return dep(a) < dep(b); });
  sort(all(MT), [&](auto& a, auto& b) -> bool { return dep(a) < dep(b); });

  auto dist = [&](pair<int, int> X, pair<int, int> Y) -> int {
    int x = 0;
    x += tree.dist(X.fi, Y.fi);
    x += tree.dist(X.fi, Y.se);
    x += tree.dist(X.se, Y.fi);
    x += tree.dist(X.se, Y.se);
    return x;
  };
  SHOW(MS, MT);
  int sk = 0, tk = 0;
  while (len(MS)) {
    vc<int> pos(step + 1);
    if (dep(MS.back()) < dep(MT.back())) {
      pair<int, int> T = POP(MT);
      // 一番近い辺をとってくる
      auto comp = [&](pair<int, int>& A, pair<int, int>& B) -> bool {
        return dist(A, T) < dist(B, T);
      };
      auto it = min_element(all(MS), comp);
      pair<int, int> S = *it;
      MS.erase(it);
      SHOW(S, T);

      // S を T に運ぶ
      FOR(i, step + 1) pos[i] = i % 2 == 0 ? S.fi : S.se;
      int t = 2 * (tk++);
      auto path = tree.restore_path(pos[t], T.fi);
      FOR(i, len(path)) pos[t + i] = path[i];
      t = t + len(path) - 1;
      assert(pos[t] == T.fi);
      FOR(i, t + 1, step + 1) pos[i] = T.fi + T.se - pos[i - 1];
    } else {
      pair<int, int> S = POP(MS);
      // 一番近い辺をとってくる
      auto comp = [&](pair<int, int>& A, pair<int, int>& B) -> bool {
        return dist(A, S) < dist(B, S);
      };
      auto it = min_element(all(MT), comp);
      pair<int, int> T = *it;
      MT.erase(it);

      // S を T に運ぶ
      FOR(i, step + 1) pos[i] = (step + i) % 2 == 0 ? T.fi : T.se;
      int t = step - 2 * (sk++);
      auto path = tree.restore_path(pos[t], S.fi);
      FOR(i, len(path)) pos[t - i] = path[i];
      t = t - len(path) + 1;
      assert(pos[t] == S.fi);
      FOR_R(i, t) pos[i] = S.fi + S.se - pos[i + 1];
    }

    SHOW(pos);
    assert(len(pos) == step + 1);
    assert(inS[pos[0]]);
    assert(inT[pos[step]]);
    FOR(i, step) assert(tree.dist(pos[i], pos[i + 1]) == 1);
    FOR(i, step + 1) ANS[i].eb(pos[i]);
  }

  FOR(i, step + 1) {
    vc<int> V = ANS[i];
    sort(all(V));
    FOR(i, len(V) - 1) assert(V[i] != V[i + 1]);
  }

  return {true, ANS};
}

void out(vvc<int> ANS) {
  Yes();
  print(len(ANS) - 1);
  for (auto& V : ANS) {
    for (auto& v : V) v = (v / 2) + 1;
    print(V);
  }
}

void solve() {
  INT(N, M);
  STR(S, T);

  Graph<int, 0> G(N + N);
  UnionFind uf(N + N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    G.add(2 * a, 2 * b + 1);
    G.add(2 * a + 1, 2 * b);
    uf.merge(2 * a, 2 * b + 1);
    uf.merge(2 * a + 1, 2 * b);
  }
  G.build();

  if (S == T) {
    vvc<int> ANS(1);
    FOR(i, N) if (S[i] == '1') ANS[0].eb(2 * i + 0);
    return out(ANS);
  }

  vvc<int> vs(N + N);
  FOR(i, N + N) vs[uf[i]].eb(i);

  FOR(parity, 2) {
    vvc<int> A(N + N), B(N + N);
    FOR(v, N) {
      if (S[v] == '1') {
        int x = 2 * v + 0;
        A[uf[x]].eb(x);
      }
      if (T[v] == '1') {
        int x = 2 * v + parity;
        B[uf[x]].eb(x);
      }
    }

    vc<int> new_idx(N + N, -1);

    int step = 2 * N - parity;
    vv(int, ANS, step + 1, 0);

    FOR(r, N + N) {
      if (uf[r] != r) continue;
      vc<int> S, T;
      vc<int> V = vs[r];
      int n = len(V);

      FOR(i, n) new_idx[V[i]] = i;
      for (auto& v : A[r]) S.eb(new_idx[v]);
      for (auto& v : B[r]) T.eb(new_idx[v]);
      FOR(i, n) new_idx[V[i]] = -1;
      Graph<int, 0> H = G.rearrange(V);

      auto [ok, way] = solve_connected(H, S, T, step);
      if (!ok) {
        ANS.clear();
        break;
      }
      FOR(i, step + 1) {
        for (auto& k : way[i]) ANS[i].eb(V[k]);
      }
    }
    if (ANS.empty()) continue;
    return out(ANS);
  }
  No();
}

signed main() {
  INT(T);
  FOR(T) solve();
}