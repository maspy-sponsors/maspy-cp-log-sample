#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;

//
array<ll, 4> get(ll L, ll R) {
  array<ll, 4> A{};
  if (L != 0) {
    auto B = get(0, R);
    auto C = get(0, L);
    FOR(i, 4) A[i] = B[i] - C[i];
    return A;
  }
  auto [q, r] = divmod<ll>(R, 4);
  FOR(i, 4) A[i] = q;
  FOR(i, r) A[i]++;
  return A;
}

void solve() {
  LL(N, X);

  /*
  あー全然違った
  */

  mint ANS = 0;

  // L even R even
  // むり

  // L even R odd
  // 単に mod 4 的な何か
  // R-L+1 が 4 の倍数だと good

  // L odd R even
  // むり

  // L odd R odd
  // L=1 だけ可能
  // 実質 even, odd case
  // mod 4 で 3

  /*
  L=1
  */
  // FOR(x, X, N + 1) {
  //   if (x % 4 == 3) ANS += 1;
  // }

  // // L even R odd
  // FOR(L, 1, X + 1) {
  //   FOR(R, X, N + 1) {
  //     if (L % 2 == 0 && R % 2 == 1 && (R - L + 1) % 4 == 0) ANS += 1;
  //   }
  // }

  auto A = get(1, X + 1);
  auto B = get(X, N + 1);

  ANS += B[3];
  FOR(a, 4) FOR(b, 4) {
    if (a % 2 == 0 && b % 2 == 1 && (b - a + 1) % 4 == 0)
      ANS += mint(A[a]) * B[b];
  }
  print(ANS);

  // map<tuple<ll, ll, ll, ll, ll>, mint> MP;
  // auto F = [&](auto& F, ll L0, ll L1, ll R0, ll R1, ll parity) -> mint {
  //   // xor==0, R-L の parity も指定
  //   assert(L0 <= L1 && R0 <= R1);
  //   if (L0 == L1 && R0 == R1) {
  //     return (parity == 0 ? 1 : 0);
  //   }

  //   tuple<ll, ll, ll, ll, ll> key = {L0, L1, R0, R1, parity};
  //   if (MP.count(key)) return MP[key];

  //   mint ANS = 0;
  //   FOR(a, 2) {
  //     FOR(b, 2) {
  //       if ((b - a + 1 + parity) % 2 != 0) continue;
  //       /*
  //       L0<=2L+a<=L1
  //       */
  //       ll A0 = ceil<ll>(L0 - a, 2);
  //       ll A1 = floor<ll>(L1 - a, 2);
  //       ll B0 = ceil<ll>(R0 - b, 2);
  //       ll B1 = floor<ll>(R1 - b, 2);
  //       if (A0 > A1) continue;
  //       if (B0 > B1) continue;

  //       /*
  //       2L+a,...,2R+b
  //       1 の位の条件をチェック
  //       */
  //       FOR(p, 2) {
  //         // a,...,2p+b
  //         ll cnt = 0;
  //         cnt += (b ? p + 1 : p);
  //         if (cnt % 2 != 0) continue;
  //         ANS += F(F, A0, A1, B0, B1, p);
  //       }
  //     }
  //   }
  //   return MP[key] = ANS;
  // };

  // mint ANS = 0;
  // ANS += F(F, 1, X, X, N, 0);
  // ANS += F(F, 1, X, X, N, 1);
  // print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}