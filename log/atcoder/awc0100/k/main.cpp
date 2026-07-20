#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/kdtree/kdtree_acted_monoid.hpp"
#include "alg/acted_monoid/min_add.hpp"

void solve() {
  LL(N, K, Q);
  ll n = N - K + 1;
  vi A(n + 1);
  vi X(N);

  auto get_range = [&](int j) -> pair<int, int> {
    /*
    i<=j<i+K
    j-K<i<=j
    */
    int s = j - K + 1;
    int t = j + 1;
    chmax(s, 0);
    chmin(t, n);
    return {s, t};
  };
  FOR(j, N) {
    LL(x);
    auto [s, t] = get_range(j);
    A[s] += x, A[t] -= x;
    X[j] = x;
  }
  A = cumsum<ll>(A, 0);

  vc<int> C(n + 1);
  FOR(j, N) {
    INT(x);
    auto [s, t] = get_range(j);
    C[s] += x, C[t] -= x;
  }
  C = cumsum<int>(C, 0);

  vc<int> xs(n), ys(n);
  vi W(n);
  FOR(i, n) xs[i] = i, ys[i] = C[i], W[i] = A[i];
  KDTree_ActedMonoid<ActedMonoid_Min_Add<ll>, int> KDT(xs, ys, W);

  auto Q1 = [&]() -> void {
    INT(j, y);
    --j;
    y -= X[j];
    X[j] += y;
    auto [s, t] = get_range(j);
    // for (int i = s; i < t; ++i) A[i] += y;
    KDT.apply(s, t, 0, K + 1, y);
  };

  auto Q2 = [&]() -> void {
    INT(x, y);

    // FOR(i, n) {
    //   if (C[i] >= x) chmin(ans, A[i]);
    // }
    ll ans = KDT.prod(0, n, x, K + 1);
    if (ans == infty<ll>) return print("IMPOSSIBLE");
    print(ans);
  };

  FOR(Q) {
    INT(t);
    if (t == 1) Q1();
    if (t == 2) Q2();
  }
}

signed main() {
  solve();
  return 0;
}