#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/stable_roommate.hpp"

// One city can not have the same cost of building the rail with two different
// cities.

void solve() {
  INT(N);
  vvc<int> dat;
  vv(int, A, N, N);
  FOR(v, N) {
    FOR(i, N) {
      if (i != v) read(A[v][i]);
    }
    auto I = argsort(A[v]);
    assert(I[0] == v);
    I.erase(I.begin());
    dat.eb(I);
  }
  auto ANS = stable_roommate(dat);
  if (ANS.empty()) return print(-1);

  vc<int> match(N, -1);
  for (auto& [a, b] : ANS) {
    assert(match[a] == -1 && match[b] == -1);
    match[a] = b, match[b] = a;
  }

  // check
  FOR(v, N) assert(match[v] != -1 && match[v] != v && match[match[v]] == v);
  FOR(x, N) FOR(y, N) {
    if (x == y || y == match[x]) continue;
    if (A[x][y] < A[x][match[x]] && A[y][x] < A[y][match[y]]) {
      assert(0);
    }
  }
  FOR(v, N) print(match[v] + 1);
}

signed main() {
  solve();
  return 0;
}