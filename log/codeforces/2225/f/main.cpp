#include "my_template.hpp"
#include "other/io.hpp"
#include "string/suffix_array.hpp"

/*
K 個以上にきって、辞書 K 番目を最大化

ほんとに？？
じゃあ、単に大きい部分文字列をとるだけだ

うそでした

なるべく個数の少ない解を考える

目標 T
T 以上であるようなもの 1:
01列を考える
1*->1
00->0

これで分割の個数を小さくできる

K>=2 のときは、ちょうど K 個としてよい

K=1 のとき
分割して、最小文字列を大きくしたい
*/

void solve() {
  LL(N, L, K);
  pi ANS = {0, 0};

  STR(S);
  Suffix_Array<0> X(S);

  auto upd = [&](int L, int R) -> void {
    if (ANS.se == 0) ANS = {L, R};
    auto [a, b] = ANS;
    SHOW(N, S, L, R, a, b);
    int k = X.compare(L, R, a, b);
    SHOW(k);
    if (k == 1) ANS = {L, R};
  };

  if (K == 1) {
    // これは全体しかないか！
    if (L <= N) upd(0, N);
  } else {
    // ちょうど K 個を目指す
    FOR(i, N) {
      auto check = [&](int j) -> bool {
        SHOW(i, j);
        if (0 < i && i < L) return false;
        if (0 < N - j && N - j < L) return false;
        ll ma = 1;
        ma += floor<ll>(i, L);
        ma += floor<ll>(N - j, L);
        return ma >= K;
      };

      ll n = [&]() -> ll {
        if (check(N)) return N;
        return binary_search(check, i, N, 0);
      }();
      if (n - i < L) continue;
      upd(i, n);
    }
  }
  auto [l, r] = ANS;
  if (l == r) return NO();
  string out = {S.begin() + l, S.begin() + r};
  YES();
  print(out);
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}
