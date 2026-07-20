#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);

  vc<pi> XY;
  FOR(x, -N, N + 1) FOR(y, -N, N + 1) {
    if (x * x + y * y == M) XY.eb(x, y);
  }

  auto isin = [&](ll x, ll y) -> bool {
    return (0 <= x && x < N && 0 <= y && y < N);
  };

  vv(int, dist, N, N, -1);
  deque<pi> que;
  auto add = [&](int x, int y, int d) -> void {
    if (dist[x][y] == -1) {
      dist[x][y] = d;
      que.eb(x, y);
    }
  };
  add(0, 0, 0);

  while (len(que)) {
    auto [x, y] = POP(que);
    for (auto &&[dx, dy] : XY) {
      int nx = x + dx, ny = y + dy;
      if (isin(nx, ny)) {
        add(nx, ny, dist[x][y] + 1);
      }
    }
  }
  FOR(x, N) print(dist[x]);
}

signed main() {
  solve();

  return 0;
}
