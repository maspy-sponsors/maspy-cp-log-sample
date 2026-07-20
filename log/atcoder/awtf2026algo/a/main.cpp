#include "my_template.hpp"
#include "other/io.hpp"

#include "random/shuffle.hpp"
#include "mod/modint.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/base.hpp"

/*
START 11:00

流石にカットで考えるか？
あるマージについて、左右の部分木にある 0-1 の個数を足す

予想としては
*/

void test() {
  vi S;
  // int a = 0, b = 7;
  int a = 0, b = 3;
  FOR(1 << 20) {
    vi A(7);
    FOR(i, 7) A[i] = RNG(1, TEN[16]);
    sort(all(A));
    vi B(7);
    {
      B[3] = A[0];
      vi X = {A[1], A[2]};
      shuffle(X);
      B[1] = X[0], B[5] = X[1];
      X = {A[3], A[4], A[5], A[6]};
      shuffle(X);
      B[0] = X[0];
      B[2] = X[1];
      B[4] = X[2];
      B[6] = X[3];
    }
    ll mi = infty<ll>;
    ll best = -1;
    FOR(s, 1 << 8) {
      if (has_kth_bit(s, a)) continue;
      if (!has_kth_bit(s, b)) continue;
      ll cut = 0;
      FOR(y, 8) FOR(x, y) {
        if (has_kth_bit(s, x) == has_kth_bit(s, y)) continue;
        ll v = infty<ll>;
        FOR(j, x, y) chmin(v, B[j]);
        cut += v;
      }
      if (chmin(mi, cut)) best = s;
    }
    S.eb(best);
  }
  UNIQUE(S);
  SHOW(len(S), S);
}

/*
lca の外側：単色としてよい
i,j を含まない部分木：単色としてよい
予想：境界となる辺が存在？
ただしいはずということになった
*/

using mint = modint998;

void solve() {
  LL(N);
  vc<tuple<ll, ll, ll>> E;
  FOR(N - 1) {
    LL(a, b, c);
    --a, --b;
    E.eb(c, a, b);
  }
  sort(all(E));
  // 大きいやつから
  reverse(all(E));

  Graph<ll, 1> G(N + N - 1);
  vi W(N + N - 1);
  {
    UnionFind uf(N);
    vc<int> root(N);
    FOR(i, N) root[i] = i;
    int k = N;
    for (auto &[c, a, b] : E) {
      W[k] = c;
      int ra = root[uf[a]];
      int rb = root[uf[b]];
      G.add(k, ra);
      G.add(k, rb);
      uf.merge(a, b);
      root[uf[a]] = k;
      ++k;
    }
    G.build();
  }
  G.debug();
  ll n = N + N - 1;
  vi sz(n);
  FOR(i, N) sz[i] = 1;
  FOR(i, N, n) for (auto &e : G[i]) sz[i] += sz[e.to];

  using I = i128;
  vc<tuple<I, int, int>> dat;
  vc<int> par(n, -1);
  {
    auto dfs = [&](auto &dfs, int v, int p, I X) -> void {
      if (p != -1) dat.eb(X * sz[v], v, p);
      if (v < N) return;
      int a = -1, b = -1;
      for (auto &e : G[v]) (a == -1 ? a : b) = e.to;
      par[a] = par[b] = v;
      dfs(dfs, a, v, X + sz[b] * I(W[v]));
      dfs(dfs, b, v, X + sz[a] * I(W[v]));
    };
    dfs(dfs, n - 1, -1, 0);
  }

  using mint = modint998;
  mint ANS = 0;
  UnionFind uf(n);
  FOR(i, n) sz[i] = 0;
  FOR(i, N) sz[i] = 1;

  sort(all(dat));
  reverse(all(dat));
  for (auto &[X, a, b] : dat) {
    a = uf[a], b = uf[b];
    ANS += mint(sz[a] * sz[b]) * X;
    uf.merge(a, b);
    int c = uf[a];
    sz[c] = sz[a] + sz[b];
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}