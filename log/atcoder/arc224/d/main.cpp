#include "my_template.hpp"
#include "other/io.hpp"

/*
antichain かと思ったら違うわ
集合を K 個とってください
*/

void solve() {
  LL(N, K);

  vi A;
  FOR(x, 1, K + 1) {
    string S = to_string(x);
    A.eb(len(S));
  }

  // N
  // 2^N 通りある

  vi F(N + 1);
  {
    i128 b = 1;
    F[0] = 1;
    FOR(i, 1, N + 1) {
      b = b * (N - i + 1) / i;
      F[i] = b;
    }
  }

  int p = 0;
  ll ANS = 0;
  while (len(A)) {
    while (p <= N && F[p] == 0) ++p;
    if (p == N + 1) return print(-1);
    ANS += POP(A) * p;
    F[p]--;
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}