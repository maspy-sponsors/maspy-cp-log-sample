#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  vi X(N, 1);
  vi Y(N, 1);
  FOR(_, M) {
    LL(a, b);
    X[--a] = 0, Y[--b] = 0;
  }

  vv(ld, DP, N + 1, N + 1);
  const ld p0 = 1.0 / (N * N);
  DP[0][0] = 0.0;
  FOR(x, N + 1) FOR(y, N + 1) {
    if (x + y == 0) continue;
    ld loop = (N - x) * (N - y) * p0;
    ld pxy = x * y * p0;
    ld px = x * N * p0 - pxy;
    ld py = y * N * p0 - pxy;

    ld &val = DP[x][y];
    if (x) val += px * DP[x - 1][y];
    if (y) val += py * DP[x][y - 1];
    if (x && y) val += pxy * DP[x - 1][y - 1];
    val += 1.0;
    val /= 1 - loop;
  }
  print(DP[SUM(X)][SUM(Y)]);
}

signed main() {
  solve();
  return 0;
}