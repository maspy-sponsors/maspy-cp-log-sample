#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, K, M);
  if (K > M) return NO();

  vi S(N + 1);
  FOR(i, N + 1) { S[i] = i % K; }
  vi A(N);
  FOR(i, N) A[i] = M + bmod<ll>(S[i + 1] - S[i], M);
  YES();
  print(A);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}