#include "my_template.hpp"
#include "other/io.hpp"

#include "string/run_length.hpp"

void solve() {
  LL(N, M);
  string S;
  FOR(M) {
    STR(T);
    S += T;
  }
  vi F;
  for (auto &[a, b] : run_length(S)) F.eb(b);

  ll ANS = 0;
  ANS += F[0];
  F.erase(F.begin());
  sort(all(F));

  FOR(M - 1) {
    if (F.empty()) break;
    ANS += POP(F);
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}