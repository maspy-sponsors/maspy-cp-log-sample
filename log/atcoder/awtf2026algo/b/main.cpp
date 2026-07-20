#include "my_template.hpp"
#include "other/io.hpp"

#include "enumerate/product.hpp"
#include "mod/modint.hpp"

bool mycheck(vc<int> A);

void test(int N) {
  vc<int> A(N + N - 1);
  FOR(i, len(A)) A[i] = i;
  map<vc<int>, vc<int>> ALL;
  do {
    vc<int> X;
    FOR(i, N) {
      int cnt = 0;
      int ma = -1;
      FOR(j, i, i + N) {
        if (chmax(ma, A[j])) ++cnt;
      }
      X.eb(cnt);
    }
    ALL[X] = A;
  } while (next_permutation(all(A)));
  // SHOW(N, len(ALL));
  // for (auto& X : ALL) SHOW(X);
  enumerate_product(vc<int>(N, N), [&](vc<int> A) -> void {
    for (auto &x : A) ++x;
    bool x = ALL.count(A);
    bool y = mycheck(A);
    if (x != y) SHOW(A, x, y, ALL[A]);
  });
}

/*
4
20
106
578

雰囲気
そもそも A の cartesian tree 構造だけで決まる
根から部分木左側に配る感じ（最大距離 N まで）

言い換え問題文
各右端を終点とする区間 2N-1 個を置きます、それぞれ長さ N 以下です
ただし、区間同士は非自明には交わらないようにします
0,1,...,N-1 が含まれた回数の列として可能なのは？

うそです
長さ N の区間と交わっているのは許されている！

結局長さ N 以下というところが難しい、それはそう

素直に右から左方向になにか
手前を自由にいくつか pop
末尾が距離 N ならば pop

判定問題？？
prefix, suffix どっちから pop するねん状態
可能なら suffix 側から pop しておいた方がよさそう?
*/

bool mycheck(vc<int> A) {
  int N = len(A);
  for (auto &x : A) {
    assert(1 <= x && x <= N);
  }

  int pre = 1;
  deque<int> suf;
  FOR(i, N, N + A.back() - 1) suf.eb(i);

  FOR_R(i, N - 1) {
    int a = A[i];
    int k = pre + 1 + len(suf) - a;
    // k 個 pop します
    if (k < 0) return 0;
    if (k > pre + len(suf)) return 0;

    if (suf.empty()) {
      pre -= k;
      pre += 1;
      continue;
    }

    if (k == 0) {
      if (i + N <= suf.back()) return 0;
      pre += 1;
      continue;
    }

    suf.pop_back();
    --k;
    FOR(k) {
      if (pre > 0) {
        --pre;
      } else {
        suf.pop_front();
      }
    }
    pre += 1;
  }
  return 1;
}

/*
あとはこれを素直に dp すればいいだけ
suffix: closed [N+a,N+b]
*/
using mint = modint998;

void solve() {
  LL(N);
  VEC(ll, ub, N);

  vvv(mint, A, N, N, N);
  vc<mint> B(N + 1);

  // i==N-1
  FOR(x, 1, ub.back() + 1) {
    if (x == 1) {
      B[1] = 1;
    } else {
      A[1][0][x - 2] = 1;
    }
  }

  FOR_R(idx, N - 1) {
    ll u = ub[idx];
    vvv(mint, nxtA, N, N, N);
    vc<mint> nxtB(N + 1);
    // from prefix only
    FOR(pre, 1, N + 1) {
      mint x = B[pre];
      if (x == 0) continue;
      FOR(a, 1, u + 1) {
        // int k = pre + 1 + len(suf) - a;
        // // k 個 pop します
        // if (k < 0) return 0;
        // if (k > pre + len(suf)) return 0;

        // if (suf.empty()) {
        //   pre -= k;
        //   pre += 1;
        //   continue;
        // }
        int k = pre + 1 - a;
        if (k < 0) continue;
        if (k > pre) continue;
        int p = pre - k + 1;
        nxtB[p] += x;
      }
    }

    //
    FOR(pre, 1, N) {
      FOR(s, N) FOR(t, s, N) {
        mint x = A[pre][s][t];
        if (x == 0) continue;

        auto add_to = [&](int pre, int s, int t, mint x) -> void {
          if (t == s - 1) {
            nxtB[pre] += x;
          } else {
            assert(s <= t);
            nxtA[pre][s][t] += x;
          }
        };

        FOR(a, 1, u + 1) {
          int k = pre + 1 + (t - s + 1) - a;
          // k 個 pop します
          if (k < 0) continue;
          if (k > pre + (t - s + 1)) continue;

          if (k == 0) {
            if (idx + N <= (N + t)) continue;
            add_to(pre + 1, s, t, x);
            continue;
          }

          // suf.pop_back();
          // --k;
          // FOR(k) {
          //   if (pre > 0) {
          //     --pre;
          //   } else {
          //     suf.pop_front();
          //   }
          // }
          // pre += 1;
          --k;
          if (k <= pre) {
            add_to(pre - k + 1, s, t - 1, x);
          } else {
            add_to(1, s + (k - pre), t - 1, x);
          }
        }
      }
    }
    swap(A, nxtA);
    swap(B, nxtB);
  }
  print(SUM<mint>(B));
}

signed main() {
  // FOR(N, 2, 7) test(N);
  solve();
}