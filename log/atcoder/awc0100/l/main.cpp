#include "my_template.hpp"
#include "other/io.hpp"
#include "graph/twosat.hpp"
#include "ds/my_bitset.hpp"

/*
とりあえず two sat 二分探索が可能

あとは辞書最小化
ひとつずつ辺を足しながら判定
bitset 登場？
*/

void solve() {
  LL(N, M);
  vc<array<ll, 2>> A(N);
  FOR(i, N) read(A[i][0], A[i][1]), A[i][1] += A[i][0];
  vc<pi> dat;
  FOR(M) {
    INT(a, b);
    --a, --b;
    dat.eb(a, b);
  }

  auto check = [&](ll K) -> bool {
    // ぜんぶ K 以上
    TwoSat TS(N);
    for (auto &[a, b] : dat) {
      FOR(x, 2) FOR(y, 2) {
        if (abs(A[a][x] - A[b][y]) < K) {
          int s = (x == 0 ? ~a : a);
          int t = (y == 1 ? ~b : b);
          TS.implies(s, t);
        }
      }
    }
    return TS.calc().fi;
  };

  ll K = binary_search(check, 0, TEN[12]);

  auto idx = [&](int a, int x) -> int { return 2 * a + x; };

  int n = N + N;
  using BS = My_Bitset;

  Graph<int, 1> H(n);

  for (auto &[a, b] : dat) {
    FOR(x, 2) FOR(y, 2) {
      if (abs(A[a][x] - A[b][y]) < K) {
        int s = idx(a, x);
        int t = idx(b, 1 - y);
        H.add(s, t);
        s = idx(b, y);
        t = idx(a, 1 - x);
        H.add(s, t);
      }
    }
  }
  H.build();

  vc<BS> G(n, BS(n));

  FOR(s, n) {
    auto dfs = [&](auto &dfs, int v) -> void {
      if (G[s][v]) return;
      G[s][v] = 1;
      for (auto &e : H[v]) {
        dfs(dfs, e.to);
      }
    };
    dfs(dfs, s);
  }

  FOR(i, n) SHOW(G[i].to_string());

  // valid?
  FOR(v, N) {
    int a = 2 * v, b = 2 * v + 1;
    if (G[a][b] && G[b][a]) assert(0);
  }

  auto can_add = [&](int a, int b) -> bool {
    SHOW(a, b);
    FOR(v, N) {
      int x = idx(v, 0), y = idx(v, 1);
      bool xy = G[x][y] || (G[x][a] && G[b][y]);
      bool yx = G[y][x] || (G[y][a] && G[b][x]);
      if (xy && yx) return false;
    }
    return true;
  };

  auto add = [&](int a, int b) -> void {
    SHOW(a, b);
    FOR(v, n) {
      if (!G[v][a]) continue;
      G[v] |= G[b];
    }
  };

  string ANS;
  FOR(v, N) {
    int a = idx(v, 0), b = idx(v, 1);
    if (can_add(b, a)) {
      add(b, a);
      ANS += '0';
    } else {
      assert(can_add(a, b));
      add(a, b);
      ANS += '1';
    }
  }

  print(K);
  print(ANS);
}

signed main() {
  solve();
  return 0;
}