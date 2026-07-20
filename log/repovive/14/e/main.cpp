#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/shortest_path/bfs01.hpp"
#include "graph/shortest_path/restore_path.hpp"

/*
長さ 2 以上!!
とりあえず 4 以上ならできるらしい
*/

void test(int N) {
  UnionFind uf(1 << N);
  FOR(s, 1 << N) {
    vc<int> A(N);
    FOR(i, N) A[i] = s >> i & 1;
    FOR(L, N) FOR(R, L + 2, N + 1) {
      bool ok = 1;
      FOR(i, L, R) ok = ok && (A[i] == A[L + R - 1 - i]);
      if (!ok) continue;
      vc<int> B = A;
      FOR(j, L, R) B[j] = 1 - B[j];
      int t = 0;
      FOR(i, N) t += B[i] << i;
      uf.merge(s, t);
    }
  }
  SHOW(N, uf.n_comp);
}

pair<bool, vc<pi>> naive(int N, vc<int> A, vc<int> B) {
  int X = 0, Y = 0;
  FOR(i, N) X += A[i] << i;
  FOR(i, N) Y += B[i] << i;

  Graph<int, 0> G(1 << N);
  map<pi, pi> MP;
  FOR(s, 1 << N) {
    vc<int> A(N);
    FOR(i, N) A[i] = s >> i & 1;
    FOR(L, N) FOR(R, L + 2, N + 1) {
      bool ok = 1;
      FOR(i, L, R) ok = ok && (A[i] == A[L + R - 1 - i]);
      if (!ok) continue;
      vc<int> B = A;
      FOR(j, L, R) B[j] = 1 - B[j];
      int t = 0;
      FOR(i, N) t += B[i] << i;
      // uf.merge(s, t);
      G.add(s, t);
      MP[mp(s, t)] = mp(L, R);
    }
  }
  G.build();

  // {
  //   auto dist = warshall_floyd<int>(G);
  //   int ma = 0;
  //   FOR(i, 1 << N) chmax(ma, MAX(dist[i]));
  //   SHOW(N, ma);
  // }

  auto [dist, par] = bfs01<int>(G, X);

  if (dist[Y] == infty<int>) return {false, {}};
  auto path = restore_path(par, Y);
  vc<pi> ANS;
  FOR(i, len(path) - 1) {
    int x = path[i], y = path[i + 1];
    auto [L, R] = MP[mp(x, y)];
    ANS.eb(L, R);
  }

  return {true, ANS};
}

void out(vc<pi> ANS) {
  Yes();
  print(len(ANS));
  for (auto& [a, b] : ANS) print(1 + a, b);
}

void solve() {
  LL(N);
  STR(S, T);
  vc<int> A = s_to_vi(S, '0');
  vc<int> B = s_to_vi(T, '0');

  // auto [ok, ANS] = naive(N, A, B);

  if (N <= 3) {
    auto [ok, ANS] = naive(N, A, B);
    if (!ok) return No();
    return out(ANS);
  }

  vc<pi> ANS;
  while (N >= 9) {
    vc<int> AA = {A.end() - 5, A.end()};
    vc<int> BB = {B.end() - 5, B.end()};
    FOR(5) POP(A), POP(B);
    N -= 5;

    auto [ok, sub] = naive(5, AA, BB);
    assert(ok);
    for (auto& [a, b] : sub) ANS.eb(N + a, N + b);
  }

  auto [ok, sub] = naive(N, A, B);
  assert(ok);
  concat(ANS, sub);

  out(ANS);
}

signed main() {
  // FOR(N, 1, 10) test(N);
  INT(T);
  FOR(T) solve();
  return 0;
}  // END: main.cpp
