#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/dominator_tree.hpp"
#include "mod/modint.hpp"
#include "ds/unionfind/unionfind.hpp"
#include "graph/tree.hpp"

/*
blocked の扱いもある！

どのパスも通りません、でひとつの同値類
*/

using mint = modint998;

void solve() {
  LL(H, W);

  VEC(string, G, H);

  vc<pi> que;
  FOR(x, H) FOR(y, W) que.eb(x, y);
  auto isin = [&](int x, int y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W);
  };
  int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
  int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
  while (len(que)) {
    auto [x, y] = POP(que);
    if (!isin(x, y)) continue;
    if (G[x][y] == '0') continue;
    int u = (x == 0 || G[x - 1][y] == '0');
    int l = (y == 0 || G[x][y - 1] == '0');
    int d = (x == H - 1 || G[x + 1][y] == '0');
    int r = (y == W - 1 || G[x][y + 1] == '0');
    if ((x + y != 0 && u + l == 2) || (x + y != H + W - 2 && r + d == 2)) {
      G[x][y] = '0';
      FOR(d, 4) que.eb(x + dx[d], y + dy[d]);
    }
  }
  FOR(i, H) SHOW(G[i]);
  ll bad = 0;
  FOR(i, H) FOR(j, W) bad += (G[i][j] == '0');
  SHOW(bad);
  if (G[0][0] == '0') {
    mint ANS = mint(2).pow(bad) - 1;
    return print(ANS);
  }

  vv(int, idx, H, W, -1);
  int n = 0;
  FOR(i, H) FOR(j, W) {
    if (G[i][j] == '0') continue;
    idx[i][j] = n++;
  }

  Graph<int, 1> G1(n), G2(n);
  FOR(x, H) FOR(y, W) {
    FOR(d, 2) {
      int xx = x + dx[d];
      int yy = y + dy[d];
      if (!isin(xx, yy)) continue;
      int s = idx[x][y], t = idx[xx][yy];
      if (s == -1 || t == -1) continue;
      G1.add(s, t);
      G2.add(t, s);
    }
  }
  G1.build();
  G2.build();
  vc<int> par1 = dominator_tree(G1, idx[0][0]);
  vc<int> par2 = dominator_tree(G2, idx[H - 1][W - 1]);

  Graph<int, 1> T(n);
  FOR(i, 1, n) T.add(par1[i], i);
  T.build();
  Tree<decltype(T)> tree(T);

  UnionFind uf(n);
  FOR(i, n) {
    int j = par2[i];
    if (j == -1) continue;
    if (tree.in_subtree(j, i)) uf.merge(i, j);
  }
  SHOW(uf.get_all());

  mint ANS = 0;
  ANS += mint(2).pow(bad) - 1;
  FOR(r, n) {
    if (uf[r] == r) {
      int k = uf.size(r);
      ANS += mint(2).pow(k) - 1;
    }
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}