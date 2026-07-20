#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  vvc<int> dat(M);
  FOR(i, M) {
    LL(k);
    VEC(int, A, k);
    dat[i] = A;
  }

  FOR(a, 1, N + 1) FOR(b, 1, a) {
    bool ok = 0;
    FOR(i, M) {
      bool xa = 0, xb = 0;
      for (auto &&x : dat[i]) {
        if (x == a) xa = 1;
        if (x == b) xb = 1;
      }
      if (xa && xb) ok = 1;
    }
    if (!ok) return No();
  }
  Yes();
}

signed main() {
  solve();

  return 0;
}
