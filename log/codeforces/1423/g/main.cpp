#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/segtree.hpp"
#include "ds/fastset.hpp"
#include "alg/monoid/add.hpp"
#include "ds/segtree/dual_segtree.hpp"

/*
[a,b] 同時に含んだら -1 します
b==a+1 であるもの：別に管理する
それ以外は O(N+Q) 個である
これの処理は長方形領域で 1,a,b,ab などの和をとることができればよい

b==a+1 であるものの処理
これもやる

type 1: 長さ 1
i-1 i coef
-1 K -1
これも結局、O(N) 回しか増減しないので区間ではなく点単位

type 2
l,r,coef
-1 K -1

は？区別しなくていいじゃないか
----
[i,j] を同時に含むパターンとは
[p,p+K-1]
p<=i<=p+K-1
p<=j<=p+K-1
0<=p,p+K-1<=N-1

結局
max(0,j+1-K)<=p
p<=min(i,N-K)

ANS[K]を管理
定数個の区間に分けて1次式を足すだと思われる
*/

#define int long long

void solve() {
  INT(N, Q);
  VEC(int, AA, N);
  vc<int> A(N);
  vc<tuple<int, int, int>> QUERY;
  vc<int> key = AA;
  key.eb(0);
  FOR(Q) {
    INT(t);
    if (t == 2) {
      INT(x);
      QUERY.eb(-1, x, -1);
    }
    if (t == 1) {
      INT(L, R, x);
      --L;
      QUERY.eb(L, R, x);
      key.eb(x);
    }
  }
  UNIQUE(key);
  for (auto &x : AA) x = LB(key, x);
  for (auto &[l, r, x] : QUERY) {
    if (x != -1) x = LB(key, x);
  }
  int K = len(key);

  // 左端
  // 最初全部 0 であるところから
  FastSet F(N);
  vc<set<int>> VtoI(K);
  FOR(x, K) VtoI[x].insert(-1);
  VtoI[0].insert(0);
  auto split = [&](int i) -> void {
    if (i < 0 || i == N || F[i]) return;
    A[i] = A[F.prev(i)];
    F.insert(i);
    VtoI[A[i]].insert(i);
  };

  vc<tuple<int, int, int>> MYQUERY;
  FastSet TP0(N);
  FastSet TP1(N);  // 区間の右端
  FastSet TP2(N);  // 必ず幅 1
  vc<int> B(N);    // prev same

  auto rm = [&](int i) -> void { MYQUERY.eb(B[i], i, -1); };
  auto add = [&](int i) -> void { MYQUERY.eb(B[i], i, 1); };

  F.insert(0);
  FOR(i, N) B[i] = i - 1;
  FOR(i, N - 1) { add(i + 1); }
  TP0.insert(0);
  FOR(i, 1, N) TP1.insert(i);

  auto upd_at = [&](int i) -> void {
    int L = i - 1;
    if (F[i]) {
      int x = A[i];
      auto &S = VtoI[x];
      auto it = prev(S.lower_bound(i));
      L = *it;
      L = (F.next(L + 1)) - 1;
      assert(L < i);
    }
    if (B[i] == L) return;
    if (TP1[i] || TP2[i]) rm(i);
    TP0.erase(i), TP1.erase(i), TP2.erase(i);
    B[i] = L;
    if (L == -1) {
      TP0.insert(i);
      return;
    }
    (L == i - 1 ? TP1 : TP2).insert(i);
    add(i);
  };
  auto change = [&](int L, int R, int x) -> void {
    split(L), split(R);
    vc<int> X;
    X.eb(x);
    F.enumerate(L, R, [&](int i) -> void {
      X.eb(A[i]);
      VtoI[A[i]].erase(i);
      F.erase(i);
    });
    F.insert(L);
    A[L] = x;
    VtoI[x].insert(L);
    /*
    A,F はこの時点で完成している
    [L,R) 内
    L 個別対応、他は 1 に変更される
    あとは、[L,R) 内の要素 (or x) の next が R 以上ならばそこが変更される
    */
    upd_at(L);
    // [L+1,R)
    TP0.enumerate(L + 1, R, [&](int i) -> void {
      upd_at(i);
      assert(!TP0[i]);
    });
    TP2.enumerate(L + 1, R, [&](int i) -> void {
      upd_at(i);
      assert(!TP2[i]);
    });
    for (auto &x : X) {
      auto &S = VtoI[x];
      // vc<int> tmp(all(S));
      auto it = S.lower_bound(R);
      if (it == S.end()) continue;
      int i = *it;
      upd_at(i);
    }
  };

  FOR(i, N) change(i, i + 1, AA[i]);

  for (auto &[L, R, x] : QUERY) {
    if (L != -1) {
      change(L, R, x);
    } else {
      MYQUERY.eb(-1, R, -1);
    }
  }
  /*
  [i,j] を同時に含むパターンとは
  [p,p+K-1]
  p<=i<=p+K-1
  p<=j<=p+K-1
  0<=p,p+K-1<=N-1

  結局
  max(0,j+1-K)<=p
  p<=min(i,N-K)

  ANS[K]を管理
  定数個の区間に分けて1次式を足すだと思われる
  */

  // AK+B
  Dual_SegTree<Monoid_Add<ll>> segA(N + 1);
  Dual_SegTree<Monoid_Add<ll>> segB(
      N + 1, [&](ll K) -> ll { return K * (N - K + 1); });

  for (auto &[i, j, cf] : MYQUERY) {
    if (i == -1) {
      ll K = j;
      ll ans = segA.get(K) * K + segB.get(K);
      print(ans);
    } else {
      auto f = [&](ll K) -> ll {
        ll lo = max<ll>(0, j + 1 - K);
        ll hi = min<ll>(i, N - K);
        return max<ll>(0, hi - lo + 1);
      };
      // FOR(k, N + 1) segB.apply(k, k + 1, -cf * f(k));
      // continue;
      vc<int> tmp;
      tmp.eb(0);
      tmp.eb(j + 1), tmp.eb(N - i);
      tmp.eb(N);
      tmp.eb(j - i);
      vc<int> cut;
      for (auto &k : tmp) {
        FOR(d, -2, 3) cut.eb(k + d);
      }
      UNIQUE(cut);
      FOR(p, len(cut) - 1) {
        int L = cut[p], R = cut[p + 1];
        if (!(0 <= L && L <= N)) continue;
        // FOR(K, L, R) segB.apply(K, K + 1, -cf * f(K));
        // continue;
        if (R == L + 1) {
          segB.apply(L, L + 1, -cf * f(L));
          continue;
        }
        int K = L;
        if (0 <= j + 1 - K) {
          if (i <= N - K) {
            if (j + 1 - K > i) {
              continue;
            }
            // [j+1-K,i]
            // i-j+K
            segA.apply(L, R, -cf);
            segB.apply(L, R, -cf * (i - j));
            // FOR(K, L, R) segB.apply(K, K + 1, -cf * f(K));
          } else {
            // [j+1-K,N-K]
            segB.apply(L, R, -cf * (N - j));
            // FOR(K, L, R) segB.apply(K, K + 1, -cf * f(K));
          }
        } else {
          if (i <= N - K) {
            // [0,i]
            segB.apply(L, R, -cf * (i + 1));
            // FOR(K, L, R) segB.apply(K, K + 1, -cf * f(K));
          } else {
            // [0,N-K]
            // FOR(K, L, R) segB.apply(K, K + 1, -cf * f(K));
            segA.apply(L, R, -cf * (-1));
            segB.apply(L, R, -cf * (N + 1));
          }
        }
      }
    }
  }
  // print("len=", len(MYQUERY));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}