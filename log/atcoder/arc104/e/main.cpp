#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "seq/longest_increasing_subsequence.hpp"
#include "enumerate/multiset.hpp"

using mint = modint107;

void solve() {
  LL(N);
  VEC(ll, A, N);

  vi X = A;
  X.eb(0);
  UNIQUE(X);

  int K = len(X) - 1;

  vc<int> ord(N);
  FOR(i, N) ord[i] = i;

  vc<mint> ANS(N + 1);

  vc<int> rk(N);
  vc<int> INC(K);
  do {
    FOR(i, N) rk[ord[i]] = i;
    int lis = len(longest_increasing_subsequence(rk));

    enumerate_multiset(N, K, [&](vc<int>& CNT) -> void {
      ++ccc;
      // ord[i] が座圧区間の S[i] を使います
      vc<int> S;
      FOR(i, K) FOR(CNT[i]) S.eb(i);
      FOR(i, N) {
        if (A[ord[i]] <= X[S[i]]) return;
      }
      fill(all(INC), 0);
      // 右にいくときには真に大きくなる
      FOR(i, N - 1) {
        int a = ord[i], b = ord[i + 1];
        if (S[i] == S[i + 1] && a < b) INC[S[i]]++;
      }

      mint ans = 1;
      FOR(k, K) {
        int c = CNT[k], inc = INC[k], w = X[k + 1] - X[k];
        ans *= C_negative<mint, 1>(c + 1, w - 1 - inc);
      }
      SHOW(ord, rk, S, ans);
      ANS[lis] += ans;
    });
  } while (next_permutation(all(ord)));

  SHOW(ANS);

  mint x = 0, y = 0;
  FOR(k, N + 1) {
    x += ANS[k] * k;
    y += ANS[k];
  }
  mint prod = 1;
  for (auto& a : A) prod *= a;
  assert(y == prod);
  print(x / y);
}

signed main() {
  solve();
  return 0;
}
