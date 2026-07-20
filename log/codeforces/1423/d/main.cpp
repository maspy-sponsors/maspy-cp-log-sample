#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(H, W, K, T, N);
  int sx = -1, sy = -1, tx = -1, ty = -1;
  vv(int, idx, H, W);
  vc<pair<int, int>> V;
  int n = 0;
  FOR(x, H) {
    FOR(y, W) {
      CHAR(ch);
      if (ch == 'L') {
        idx[x][y] = -1;
      }
      elif (ch == 'S' || ch == 'P' || ch == 'M') {
        idx[x][y] = n;
        V.eb(x, y);
        ++n;
        if (ch == 'P') {
          tx = x, ty = y;
        }
        if (ch == 'M') {
          sx = x, sy = y;
        }
      }
      else {
        assert(0);
      }
    }
  }

  auto isin = [&](int x, int y) -> bool {
    return (0 <= x && x < H && 0 <= y && y < W && idx[x][y] != -1);
  };
  int dx[] = {1, 0, -1, 0, 0};
  int dy[] = {0, 1, 0, -1, 0};
  using ARR = array<array<int, 5>, 5>;
  vc<ARR> G(n);

  FOR(i, n) {
    auto [x, y] = V[i];
    FOR(wind, 5) {
      FOR(me, 5) {
        // and there must be a 4-connected path through the sea from the
        // starting field. A 4-connected path is a path where you can go from
        // one cell to another only if they share a side.
        // ほんとかよ
        // 違うと思っています
        // 定義は推測!!!
        int x1 = dx[wind], y1 = dy[wind];
        int x2 = dx[me], y2 = dy[me];
        bool ok = 0;
        ok = ok || (isin(x + x1, y + y1) && isin(x + x1 + x2, y + y1 + y2));
        ok = ok || (isin(x + x2, y + y2) && isin(x + x1 + x2, y + y1 + y2));
        // あーこれも？
        ok = ok || (x1 + x2 == 0 && y1 + y2 == 0);
        if (ok) {
          G[i][wind][me] = idx[x + x1 + x2][y + y1 + y2];
        } else {
          G[i][wind][me] = -1;
        }
      }
    }
  }

  VEC(char, WIND, N);
  while (len(WIND) > (K + 10) * (T + 10)) WIND.pop_back();

  vc<pair<int, int>> shop;
  FOR(T) {
    INT(x, y, day);
    int i = idx[x][y];
    // たぶん
    assert(i != -1);
    shop.eb(day, i);
  }

  // のこり HP として可能な max
  vc<int> dp(n, -infty<int>);
  dp[idx[sx][sy]] = K;
  SHOW(idx[sx][sy], idx[tx][ty]);

  string DIR = "SENWC";
  FOR(d, len(WIND)) {
    int wind = DIR.find(WIND[d]);
    vc<int> newdp(n, -infty<int>);
    FOR(v, n) {
      if (dp[v] <= 0) continue;
      for (int w : G[v][wind]) {
        if (w == -1) continue;
        chmax(newdp[w], dp[v] - 1);
      }
    }
    swap(dp, newdp);
    if (dp[idx[tx][ty]] >= 0) {
      // たぶん >= 0, たぶん ANS=d+1
      return print(d + 1);
    }
    for (auto &[a, b] : shop) {
      if (a == d + 1) {
        // たぶん d+1
        if (dp[b] >= 0) {
          // たぶん 0
          dp[b] = K;
        }
      }
    }

    // FOR(i, n) {
    //   if (dp[i] >= 0) SHOW(n, i, d, V[i], dp[i]);
    // }
    // SHOW("---------");
  }
  print(-1);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}