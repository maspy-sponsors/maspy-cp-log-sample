#include "my_template.hpp"
#include "other/io.hpp"

#include "enumerate/labeled_tree.hpp"
#include "graph/tree.hpp"

ll f(int N, vc<pair<int, int>> E) {
  Graph<int, 0> G(N);
  for (auto &[a, b] : E) G.add(a, b);
  G.build();
  Tree<decltype(G)> tree(G);
  ll K = 0;
  FOR(i, N) K += tree.dist(i, (i + 1) % N);
  return K;
}

void test(int N) {
  vi S;
  enumerate_labeled_tree(N,
                         [&](vc<pair<int, int>> E) -> void { S.eb(f(N, E)); });
  UNIQUE(S);

  vi T;
  vc<int> A(N);
  FOR(i, N) A[i] = i;
  do {
    int K = 0;
    FOR(i, N) K += abs(A[i] - A[(i + 1) % N]);
    T.eb(K);
  } while (next_permutation(all(A)));
  UNIQUE(T);
  SHOW(N, S, T, len(S) == len(T));
}

vc<pair<int, int>> solve(ll N, ll K) {
  if (K % 2 != 0) return {};
  K /= 2;
  if (N - 1 > K) return {};
  ll ma = 0;
  FOR(i, N / 2) ma -= i;
  FOR(i, N - N / 2, N) ma += i;
  if (ma < K) return {};
  vi L, R;
  int a = 0, b = N - 1;
  while (K > 0) {
    ll d = b - a;
    if (K >= d) {
      L.eb(a), R.eb(b);
      ++a, --b;
      K -= d;
    } else {
      L.eb(a), R.eb(a + K);
      K = 0;
    }
  }
  sort(all(L));
  sort(all(R));
  vi pos(N, -1);
  int k = 0;
  FOR(i, len(L)) {
    pos[L[i]] = k++;
    pos[R[i]] = k++;
  }
  FOR_R(i, N) {
    if (pos[i] == -1) pos[i] = k++;
  }
  vc<int> A(N);
  FOR(i, N) A[pos[i]] = i;
  vc<pair<int, int>> E;
  // FOR(i, N - 1) E.eb(A[i], A[i + 1]);
  SHOW(L, R, A);
  FOR(i, N - 1) E.eb(pos[i], pos[i + 1]);
  return E;
}

void test() {
  FOR(N, 2, 10) {
    FOR(K, 100) {
      auto E = solve(N, K);
      if (E.empty()) continue;
      int check = f(N, E);
      SHOW(N, K, E, check);
      assert(K == check);
    }
  }
}

void solve() {
  LL(N, K);
  auto E = solve(N, K);
  if (E.empty()) return print(-1);
  for (auto &[a, b] : E) print(1 + a, 1 + b);
}

signed main() {
  // FOR(N, 2, 7) test(N);
  // test();
  INT(T);
  FOR(T) solve();
  return 0;
}