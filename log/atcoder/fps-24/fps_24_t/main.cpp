#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/sum_of_rationals.hpp"
#include "poly/coef_of_rational_fps.hpp"

using mint = modint998;

/*
ほうじょ
色1
色iの長さ2以上のブロック
これで分解

まずは色 i の長さ2以上のブロックに包除係数をつけたもの
これは有理式和になる
F(x)

G(x)
[nanika 色1] 部分
F(x) の定数項を消して何かをつけたもの

1-G(x) の inv です
何もかもが有理式

a==998244353 あるけど、マジ！？


1 other 1 other
other + (1 other)^n
*/

void solve() {
  LL(N, T);
  VEC(mint, A, N);

  /*
  ax - aaxx + aaaxxx - ....
  1- 1/(1+ax)
  ax/(1+ax)

  F(x) = 1/1-sum ax/(1+ax) - 1
  */
  vc<pair<vc<mint>, vc<mint>>> dat;
  FOR(i, 1, N) {
    mint a = A[i];
    vc<mint> f = {0, a};
    vc<mint> g = {1, a};
    dat.eb(f, g);
  }
  auto [F1, F2] = sum_of_rationals<mint>(dat);
  FOR(i, len(F2)) F2[i] -= F1[i];
  // 求まったもの: other, >=1

  /*
  F(x) (ax(F(x)))
  F(x) / 1 - axF(x)

  G(x)=F1(x) / F2(x)-axF1(x)
  */
  ll n = len(F1);
  assert(len(F2) == n);
  vc<mint> G1(n + 1), G2(n + 1);
  FOR(i, n) G1[i] = F1[i];
  FOR(i, n) G2[i] += F2[i];
  FOR(i, n) G2[i + 1] -= mint(A[0]) * F1[i];

  print(coef_of_rational_fps<mint>(G1, G2, T - 1));
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}