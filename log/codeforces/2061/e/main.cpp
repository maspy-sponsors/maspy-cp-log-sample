#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M, K);
  VEC(u32, A, N);
  VEC(u32, B, M);
  vc<u32> S(1 << M);
  S[0] = u32(-1);
  FOR(i, M) FOR(s, 1 << i) S[s | 1 << i] = S[s] & B[i];

  vc<u32> F;
  F.reserve(N * M);

  FOR(i, N) {
    u32 a = A[i];
    vc<u32> X(M + 1, u32(-1));
    FOR(s, 1 << M) { chmin(X[popcnt(s)], a & S[s]); }
    FOR(i, M) F.eb(X[i] - X[i + 1]);
  }
  SHOW(F);
  sort(all(F));
  reverse(all(F));

  u64 ANS = SUM<u64>(A);
  FOR(k, K) ANS -= F[k];
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}