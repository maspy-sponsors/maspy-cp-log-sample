#include "my_template.hpp"
#include "other/io2.hpp"

#include "random/base.hpp"
#include "random/random_graph.hpp"

void norm(vc<pair<int, int>>& E) {
  for (auto& [a, b] : E)
    if (a > b) swap(a, b);
  sort(all(E));
}

vc<pair<int, int>> gen(int N) {
  int t = RNG(0, 3);
  vc<pair<int, int>> E;
  if (t == 0) {
    FOR(v, N - 1) E.eb(v, v + 1);
  }
  elif (t == 1) { FOR(v, 1, N) E.eb(0, v); }
  elif (t == 2) {
    FOR(v, 1, N) { E.eb((v - 1) / 2, v); }
  }
  else {
    E = random_tree(N);
  }
  return E;
}

void solve() {
#ifdef LOCAL
  int N = 1000;
  auto E = gen(N);
  norm(E);
  Graph<int, 0> G(N);
  for (auto& [a, b] : E) G.add(a, b);
  G.build();
#else
  LL(N);
#endif

  int QLE = 0;
  auto ASK = [&](vc<int> A) -> string {
    QLE += len(A);
#ifdef LOCAL
    string S(N, '0');
    for (auto& a : A) {
      bool ok = 1;
      for (auto& e : G[a]) {
        ok = ok && (S[e.to] == '0');
      }
      if (ok) S[a] = '1';
    }
    return S;
#endif
    for (auto& x : A) ++x;
    print("?", len(A), A);
    for (auto& x : A) --x;
    STR(T);
    string res(N, '0');
    FOR(i, len(A)) res[A[i]] = T[i];
    return res;
  };

  vvc<int> vs;
  vc<int> V(N);
  FOR(i, N) V[i] = i;

  while (len(V)) {
    if (len(V) <= 1) {
      vs.eb(V);
      break;
    }
    shuffle(V);
    string S = ASK(V);
    vc<int> X, Y;
    for (int v : V) {
      if (S[v] == '1') {
        X.eb(v);
      } else {
        Y.eb(v);
      }
    }
    vs.eb(X);
    swap(V, Y);
  }

  vc<pair<int, int>> ANS;
  auto betw = [&](vc<int> A, vc<int> B) -> void {
    // SHOW(len(A), len(B));
    vc<pair<vc<int>, vc<int>>> que;
    que.eb(A, B);
    bool F = 1;
    while (len(que)) {
      auto [A, B] = POP(que);
      if (A.empty() || B.empty()) continue;
      if (len(A) > len(B)) swap(A, B), F = 0;
      if (!F) {
        vc<int> V;
        concat(V, A, B);
        string S = ASK(V);
        vc<int> tmp;
        for (int b : B)
          if (S[b] == '0') tmp.eb(b);
        swap(B, tmp);
      }
      F = 0;
      // B must have nbd in A
      if (len(A) == 1) {
        for (int b : B) ANS.eb(A[0], b);
        continue;
      }
      vc<int> A1, A2;
      int n = len(A) / 2;
      shuffle(A);
      FOR(i, n) A1.eb(A[i]);
      FOR(i, n, len(A)) A2.eb(A[i]);
      que.eb(A1, B);
      que.eb(A2, B);
    }
  };

  FOR(j, len(vs)) FOR(i, j) { betw(vs[i], vs[j]); }

#ifdef LOCAL
  SHOW(QLE, len(ANS));
  norm(ANS);
  assert(E == ANS);
#endif

  print("!");
  for (auto& [a, b] : ANS) print(1 + a, 1 + b);

  // print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}