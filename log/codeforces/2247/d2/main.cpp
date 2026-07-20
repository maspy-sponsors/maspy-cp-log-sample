#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"

struct T {
  int mi, ma, cnt, ans;
};

struct Mono {
  using value_type = T;
  using X = value_type;
  static X op(X L, X R) {
    SHOW(L.cnt, R.cnt);
    assert(L.cnt == R.cnt);
    int ans = max(L.ans, R.ans);
    int cnt = L.cnt + R.cnt;
    if (L.ma > R.mi) chmax(ans, cnt);
    int mi = min(L.mi, R.mi);
    int ma = max(L.ma, R.ma);
    return T{mi, ma, cnt, ans};
  }
  static constexpr X unit() { return {-1, -1, -1, -1}; }
  static constexpr bool commute = 0;
};

void solve() {
  LL(N, Q);
  VEC(int, A, N);
  int n = 2;
  while (n < N) n += n;
  SHOW(n, A);
  while (len(A) < n) A.eb(TEN[9]);
  SHOW(n, A);

  auto segf = [&](int i) -> T {
    int a = A[i];
    return T{a, a, 1, 0};
  };

  SegTree<Mono> seg(n, segf);

  auto solve = [&]() -> void {
    T X = seg.prod_all();
    print(X.ans / 2);
  };

  solve();
  FOR(Q) {
    LL(i, x);
    A[i] = x;
    seg.set(i, segf(i));

    solve();
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
