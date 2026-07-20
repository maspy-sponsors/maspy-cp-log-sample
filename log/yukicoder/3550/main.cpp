#include "my_template.hpp"
#include "other/io.hpp"

/*
maximize
上の桁から
AND:1であるものだけ使って期待
OR:全部 0 だとまずいがそうでなければセーフ

AND=1 と決める
そのときの OR の最大値をチェック
*/

void solve() {
  LL(N);
  VEC(ll, A, N);
  ll ANS = 0;
  ll need = 0;

  ll ODD = 0, EVEN = 0;
  FOR(i, 30) {
    if (i % 2 == 0) EVEN |= 1LL << i;
    if (i % 2 == 1) ODD |= 1LL << i;
  }

  auto f = [&](ll x, ll a) -> ll {
    ll a0 = a & EVEN;
    ll a1 = a & ODD;
    ll x0 = x & EVEN;
    ll x1 = x & ODD;
    x0 &= a0;
    x1 |= a1;
    return x0 | x1;
  };

  FOR_R(k, 30) {
    if (k % 2 == 0) {
      ll x = EVEN;
      ll m = need | (1LL << k);
      vi B;
      for (ll a : A) {
        if ((a & m) == m) {
          B.eb(a);
        }
      }
      if (B.empty()) continue;
      for (ll b : B) x = f(x, b);
      if (ANS < x && has_kth_bit(x, k)) {
        ANS |= 1LL << k;
        need |= 1LL << k;
      }
    }
    if (k % 2 == 1) {
      ll x = EVEN;
      ll m = need;
      for (ll a : A) {
        if ((a & m) == m) {
          x = f(x, a);
        }
      }
      if (has_kth_bit(x, k)) ANS |= 1LL << k;
    }
  }
  print(ANS);
}

signed main() { solve(); }