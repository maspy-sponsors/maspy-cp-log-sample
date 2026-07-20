#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "mod/prefix_sum_of_binom.hpp"

/*
上の桁から決めていく

後ろから見る

確定 or どっちでもよい
ということになる
*/

using mint = modint998;

void solve() {
  LL(N, K);
  VEC(ll, A, N);

  auto calc = [&](ll X) -> bool {
    // X を 1 にできますか
    if (X == 0) return 1;
    ll now = 0;

    FOR_R(i, N) {
      ll a = A[i];
      if ((X & a) == X) {
        return now + 1 <= K;
      } else {
        // OR 必須です
        X &= (~a);
        ++now;
      }
    }
    return false;
  };

  ll M = 0;
  FOR_R(k, 61) {
    // M の k 桁目をどうするか

    if (calc(M | 1LL << k)) M |= 1LL << k;
  }

  // M を 1 にしましょうということで
  mint ANS = 0;
  ll X = M;
  if (X == 0) {
    // mint ANS = C<mint>(N, K);
    mint ANS = 0;
    FOR(i, K + 1) ANS += C<mint>(N, i);
    return print(ANS);
  }

  Prefix_Sum_Of_Binom_Offline<mint> SS;

  ll cnt = 0;
  FOR_R(i, N) {
    ll a = A[i];
    if ((X & a) == X) {
      // or を選んであとはなんでもよい
      // ANS += C<mint>(i, K - cnt - 1);

      // FOR(j, K - cnt) ANS += C<mint>(i, j);
      SS.add(i, K - cnt);

      // または AND を選んで続行
    } else {
      // or 強制
      ++cnt;
      X &= (~a);
    }
  }

  auto res = SS.calc();
  ANS = SUM<mint>(res);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}
