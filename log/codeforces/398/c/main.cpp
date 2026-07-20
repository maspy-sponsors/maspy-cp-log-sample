#include "my_template.hpp"
#include "other/io.hpp"
#include "enumerate/labeled_tree.hpp"
#include "enumerate/product.hpp"
#include "graph/shortest_path/warshall_floyd.hpp"
#include "random/random_graph.hpp"
#include "graph/tree.hpp"

/*
2n 頂点増やして ANS += n することを考える

[1,N] で頂点 N を使わずに目的を達成しているとする

N+1,...,N+2n
N+1,N+2n を使わずに n ペア作れれば成功
*/

void test(int N) {
  print("N=", N);
  flush();
  assert(N % 2 == 0);
  enumerate_labeled_tree(N, [&](vc<pair<int, int>> E) -> void {
    enumerate_product(vc<int>(N - 1, 2), [&](vc<int> A) -> void {
      for (auto& x : A) ++x;
      vc<int> T(N + 1);
      Graph<int, 0> G(N);
      FOR(i, N - 1) {
        auto [a, b] = E[i];
        G.add(a, b, A[i]);
        if (a > b) swap(a, b);
        FOR(k, a, b + 1) T[k] += A[i];
      }

      G.build();
      auto D = warshall_floyd<int>(G);

      auto Tc = cumsum<int>(T);
      int ok = 0;
      FOR(b, N) FOR(a, b) {
        if (a == 0 || b == N - 1) continue;
        int X = D[a][b];
        int Y = Tc[b + 1] - Tc[a];
        ok += (X == Y);
      }
      if (ok >= N / 2) {
        print("E=", E);
        print("A=", A);
        flush();
      }
    });
  });
}

/*
E= 4 2 6 4 3 5 1 3 0 1 7 0 7 6
A= 1 1 2 1 2 1 2

+8 できます
*/

// 頂点 N は使わないです
pair<vc<pair<int, int>>, vc<int>> gen(int N) {
  if (N == 12) {
    vc<pair<int, int>> E = {{5, 8}, {0, 1},  {3, 11}, {4, 9},  {6, 7}, {8, 10},
                            {1, 9}, {8, 11}, {6, 9},  {6, 11}, {2, 6}};
    vc<int> A = {1, 2, 2, 3, 3, 1, 1, 2, 3, 3, 1};
    return {E, A};
  }
  if (N == 11) {
    vc<pair<int, int>> E = {{3, 6}, {1, 7}, {5, 7}, {4, 7}, {0, 5},
                            {2, 4}, {5, 8}, {4, 9}, {6, 9}, {7, 10}};
    vc<int> A = {1, 1, 1, 3, 1, 2, 1, 3, 3, 2};
    return {E, A};
  }
  if (N == 10) {
    vc<pair<int, int>> E = {{4, 6}, {7, 9}, {4, 8}, {7, 8}, {3, 4},
                            {5, 7}, {0, 1}, {2, 8}, {1, 5}};
    vc<int> A = {2, 3, 3, 3, 2, 1, 3, 1, 1};
    return {E, A};
  }
  if (N == 9) {
    vc<pair<int, int>> E = {{6, 8}, {2, 8}, {7, 8}, {4, 6},
                            {1, 7}, {3, 5}, {5, 6}, {0, 1}};
    vc<int> A = {1, 1, 3, 3, 2, 1, 3, 1};
    return {E, A};
  }
  if (N == 8) {
    vc<pair<int, int>> E = {{6, 7}, {2, 6}, {5, 6}, {1, 4},
                            {0, 1}, {4, 6}, {3, 7}};
    vc<int> A = {3, 1, 3, 1, 2, 3, 3};
    return {E, A};
  }
  if (N >= 13) {
    int M = N % 8;
    if (M <= 4) M += 8;
    auto [E, A] = gen(M);
    while (M < N) {
      E.eb(M - 1, M), A.eb(1);  // 適当につなぐ
      E.eb(M + 4, M + 2);
      E.eb(M + 6, M + 4);
      E.eb(M + 3, M + 5);
      E.eb(M + 1, M + 3);
      E.eb(M + 0, M + 1);
      E.eb(M + 7, M + 0);
      E.eb(M + 7, M + 6);
      A.eb(1);
      A.eb(1);
      A.eb(2);
      A.eb(1);
      A.eb(2);
      A.eb(1);
      A.eb(2);
      M += 8;
    }
    assert(len(E) == N - 1);
    assert(len(A) == N - 1);
    return {E, A};
  }
  while (1) {
    auto E = random_tree(N);
    vc<int> A(N - 1);
    FOR(i, N - 1) A[i] = RNG(1, 4);
    vc<int> T(N + 1);
    Graph<int, 0> G(N);
    FOR(i, N - 1) {
      auto [a, b] = E[i];
      G.add(a, b, A[i]);
      if (a > b) swap(a, b);
      FOR(k, a, b + 1) T[k] += A[i];
    }

    G.build();
    auto D = warshall_floyd<int>(G);

    auto Tc = cumsum<int>(T);
    int ok = 0;
    FOR(b, N) FOR(a, b) {
      if (b == N - 1) continue;
      int X = D[a][b];
      int Y = Tc[b + 1] - Tc[a];
      ok += (X == Y);
    }
    if (ok >= N / 2) {
      return {E, A};
    }
  }
}

void solve() {
  INT(N);
  auto [E, A] = gen(N);
  for (auto& [a, b] : E)
    if (a > b) swap(a, b);

  Graph<ll, 0> G(N);
  vi T(N);
  FOR(i, N - 1) {
    auto [a, b] = E[i];
    G.add(a, b, A[i]);
    FOR(k, a, b + 1) T[k] += A[i];
  }
  G.build();
  Tree<decltype(G)> tree(G);
  auto Tc = cumsum<ll>(T);

  vc<pi> S;

  FOR(i, N) {
    FOR(j, i + 1, N) {
      if (j - i >= 16) break;
      ll d = tree.dist_weighted(i, j);
      ll t = Tc[j + 1] - Tc[i];
      if (d == t) S.eb(i, j);
    }
  }
  assert(len(S) >= N / 2);
  S.resize(N / 2);

  for (auto& e : G.edges) print(1 + e.frm, 1 + e.to, e.cost);
  for (auto& [a, b] : S) print(1 + a, 1 + b);
}

signed main() {
  // test(8);
  // return 0;
  solve();
}