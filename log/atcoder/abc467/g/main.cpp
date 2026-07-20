#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/wavelet_matrix/wavelet_matrix_2d_range.hpp"
#include "ds/fenwicktree/fenwicktree.hpp"
#include "alg/monoid/add_pair.hpp"

void solve() {
  LL(N, Q);
  VEC(ll, A, N);
  vc<pi> dat;
  FOR(i, N) dat.eb(i, A[i]);
  vi id(N);
  FOR(i, N) id[i] = i;

  vc<tuple<ll, ll, ll, ll, ll>> S;
  FOR(Q) {
    LL(c, x, l, r, k);
    --c;
    int off = id[c];
    int nxt = len(dat);
    dat.eb(c, x);
    S.eb(off, nxt, --l, r, k);
    id[c] = nxt;
  }

  Wavelet_Matrix_2D_Range<ll, 1, 0, FenwickTree<Monoid_Add_Pair<ll>>> WM(
      len(dat), [&](int i) -> tuple<ll, ll, pi> {
        if (i < N) return {i, A[i], {1, A[i]}};
        auto [j, k] = dat[i];
        return {j, k, {0, 0}};
      });

  for (auto &[a, b] : dat) SHOW(a, b);

  auto sol = [&](ll L, ll R, ll K) -> void {
    auto [nc, ALL] = WM.prod_all(L, R);
    ll LIM = ALL - K;
    if (LIM < 0) {
      return print(-1);
    }
    auto [y, cnt, prod] = WM.max_right(
        [&](ll y, ll c, pi prod) -> bool { return prod.se <= ALL - K; }, L, R);

    ll can = LIM - prod.se;
    can /= y;
    ll ANS = prod.fi + can;
    ANS = R - L - ANS;
    print(ANS);
  };

  FOR(q, Q) {
    auto [a, b, l, r, k] = S[q];
    ll x = dat[a].se;
    WM.multiply(a, {-1, -x});
    x = dat[b].se;
    WM.multiply(b, {1, x});
    sol(l, r, k);
  }
}

signed main() {
  solve();
  return 0;
}