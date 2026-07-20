#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, K);
  STR(S);
  ll ANS = 0;
  if (K + K > N) return print(-1);
  FOR(i, K) ANS += (S[i] == 'L');
  FOR(i, N - K, N) ANS += (S[i] == 'R');
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}