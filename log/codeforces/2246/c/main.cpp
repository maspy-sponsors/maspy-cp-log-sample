#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/segtree/segtree.hpp"
#include "alg/monoid/mul.hpp"

using mint = modint107;

/*
偶数項：マッチング
奇数項：
先頭が -1
一回だけ、+1 の形でとる
あとはマッチング

-1,[a,a][b,b][c,c][x,x+1],...
*/

void solve() {
  LL(N);
  VEC(ll, A, N);
  vi X = A;
  X.eb(-1);
  UNIQUE(X);
  ll n = len(X);
  vi F(n);
  for (auto &x : A) F[LB(X, x)]++;

  mint ANS = 0;
  {
    mint ans = 1;
    for (auto &x : F) {
      if (x != 0) ans *= mint(2).pow(x - 1);
    }
    ANS += ans;
  }
  if (F[0] > 0) {
    mint base = mint(2).pow(F[0] - 1);
    auto segf = [&](int i) -> mint {
      if (i == 0) return 1;
      if (F[i] == 0) return 1;
      return mint(2).pow(F[i] - 1);
    };

    SegTree<Monoid_Mul<mint>> seg(n, segf);
    FOR(i, 1, n - 1) {
      if (X[i] + 1 == X[i + 1] && F[i] > 0 && F[i + 1] > 0) {
        mint ans = base;
        ans *= seg.prod(0, i);
        ans *= seg.prod(i + 2, n);
        ans *= mint(2).pow(F[i] - 1);
        ans *= mint(2).pow(F[i + 1] - 1);
        ANS += ans;
      }
    }
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}