#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/unionfind.hpp"

void solve() {
  LL(N, M);
  UnionFind uf(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    uf.merge(a, b);
  }
  LL(Q);
  FOR(Q) {
    INT(a);
    --a;
    print(uf.size(a));
  }
}

signed main() {
  solve();
  return 0;
}