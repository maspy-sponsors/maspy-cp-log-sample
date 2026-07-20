#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/segtree/segtree.hpp"

struct T {
  ll ans;
  ll sum;
};

struct Mono {
  using value_type = T;
  using X = value_type;
  static X op(X L, X R) {
    ll sum = L.sum + R.sum;
    ll ans = max(L.ans, R.ans + L.sum);
    return {ans, sum};
  }
  static constexpr X unit() { return T{0, 0}; }
  static constexpr bool commute = 0;
};

// B が小さいのが後
void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  VEC(ll, B, N);

  vc<pi> dat;
  FOR(i, N) dat.eb(-B[i], i);
  vc<int> id(N);
  FOR(i, N) id[i] = i;

  vc<tuple<ll, ll, ll>> query;

  FOR(Q) {
    LL(t, i, x);
    --i;
    query.eb(t, i, x);
    if (t == 2) {
      dat.eb(-x, i);
    }
  }
  UNIQUE(dat);

  auto get_idx = [&](ll i, ll b) -> ll {
    pi k = {-b, i};
    return LB(dat, k);
  };

  auto segf = [&](ll a, ll b) -> T { return {a + b, a}; };

  ll n = len(dat);
  SegTree<Mono> seg(n);
  FOR(i, N) {
    int idx = get_idx(i, B[i]);
    seg.set(idx, segf(A[i], B[i]));
  }

  FOR(q, Q) {
    auto [t, i, x] = query[q];
    if (t == 1) {
      int idx = get_idx(i, B[i]);
      A[i] = x;
      seg.set(idx, segf(A[i], B[i]));
    } else {
      int idx = get_idx(i, B[i]);
      seg.set(idx, Mono::unit());
      B[i] = x;
      idx = get_idx(i, B[i]);
      seg.set(idx, segf(A[i], B[i]));
    }

    // FOR(i, n) {
    //   auto X = seg.get(i);
    //   SHOW(i, X.ans, X.sum);
    // }
    T S = seg.prod_all();
    print(S.ans);
  }
}

signed main() {
  solve();
  return 0;
}\
