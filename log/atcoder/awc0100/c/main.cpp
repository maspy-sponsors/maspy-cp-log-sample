#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, L, Q);
  vc<u64> A;
  FOR(N) {
    STR(S);
    u64 x = 0;
    for (auto& a : S) {
      x = 2 * x + (a - '0');
    }
    A.eb(x);
  }

  FOR(Q) {
    LL(n);
    u64 x = 0;
    FOR(n) {
      INT(i);
      --i;
      x |= A[i];
    }
    string ANS;
    FOR(L) {
      ANS += '0' + (x % 2);
      x /= 2;
    }
    reverse(all(ANS));
    print(ANS);
  }
}

signed main() {
  solve();
  return 0;
}