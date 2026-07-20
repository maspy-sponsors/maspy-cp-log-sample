#include "my_template.hpp"
#include "other/io.hpp"
#include "alg/monoid/or.hpp"
#include "ds/segtree/dual_segtree.hpp"
#include "ds/segtree/segtree.hpp"

/*
十分性の検証が課題
・A[l]&c,...,A[r]&c で v ではないものがあるか？ A[i],c は v 以上が保証

端数次と同じ
・A[l]&c,...,A[r]&c で k-th bit を含むものがあるか？
OR segtree

矩形領域
*/

void ng() { print("impossible"); }

void solve() {
  LL(K, Q);
  using T = tuple<ll, ll, ll>;
  VEC(T, dat, Q);

  Dual_SegTree<Monoid_Or<int>> dseg_hi(1 << K);
  Dual_SegTree<Monoid_Or<int>> dseg_lo(1 << K);
  for (auto &[a, b, v] : dat) {
    ll x1 = a >> K, x2 = b >> K;
    dseg_hi.apply(x1, x2 + 1, v);
    vi X = {x1, x1 + 1};
    for (auto &x : X) {
      ll l = x << K;
      ll r = l + (1 << K);
      chmax(l, a), chmin(r, b + 1);
      l -= x << K;
      r -= x << K;
      if (l <= r) dseg_lo.apply(l, r, v);
    }
  }

  vc<int> H = dseg_hi.get_all();
  vc<int> L = dseg_lo.get_all();
  using SEG = SegTree<Monoid_Or<int>>;
  SEG seg_hi(H);
  SEG seg_lo(L);

  auto check = [&](SEG &seg, int l, int r, int c, int v) -> bool {
    if (l >= r) return 1;
    return (seg.prod(l, r) & c) == v;
  };

  for (auto &[a, b, v] : dat) {
    ll x1 = a >> K, x2 = b >> K;
    vi X = {x1, x2};
    for (auto &x : X) {
      ll l = x << K;
      ll r = l + (1 << K);
      chmax(l, a), chmin(r, b + 1);
      l -= x << K;
      r -= x << K;
      if (!check(seg_lo, l, r, H[x], v)) return ng();
    }
    ++x1;
    if (x1 >= x2) continue;
    // FOR(x, x1, x2) {
    //   FOR(i, 0, 1 << K) {
    //     if ((H[x] & L[i]) != v) {
    //       print("ng", x, i);
    //       return ng();
    //     }
    //   }
    // }
    int aa = seg_hi.prod(x1, x2);
    int bb = seg_lo.prod_all();
    if ((aa & bb) != v) return ng();
  }

  print("possible");
  for (auto &x : L) print(x);
  for (auto &x : H) print(x);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}