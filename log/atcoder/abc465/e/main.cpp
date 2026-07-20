#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;
void solve() {
  STR(S);

  using ARR = array<array<mint, 1024>, 3>;

  ARR dp0{}, dp1{};

  FOR(i, len(S)) {
    int a = S[i] - '0';
    ARR ndp0{}, ndp1{};
    // 1 桁
    FOR(x, 1, 10) {
      if ((i == 0 && x < a) || (1 <= i)) {
        ndp0[x % 3][1 << x] += 1;
      }
      elif ((i == 0 && x == a)) { ndp1[x % 3][1 << x] += 1; }
    }

    FOR(mod, 3) FOR(s, 1024) {
      // 0 -> 0
      FOR(x, 10) {
        int m = (mod + x) % 3;
        int t = s | 1 << x;
        ndp0[m][t] += dp0[mod][s];
      }
      // 1 -> 0
      FOR(x, a) {
        int m = (mod + x) % 3;
        int t = s | 1 << x;
        ndp0[m][t] += dp1[mod][s];
      }
      // 1 -> 1
      FOR(x, a, a + 1) {
        int m = (mod + x) % 3;
        int t = s | 1 << x;
        ndp1[m][t] += dp1[mod][s];
      }
    }
    swap(dp0, ndp0);
    swap(dp1, ndp1);
  }

  mint ANS = 0;
  FOR(m, 3) FOR(s, 1024) {
    int cnt = 0;
    cnt += (m == 0);
    cnt += (s >> 3 & 1);
    cnt += (popcnt(s) == 3);
    if (cnt == 1) ANS += dp0[m][s] + dp1[m][s];
  }
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}