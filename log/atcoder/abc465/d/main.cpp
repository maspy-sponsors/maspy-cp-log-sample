#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(X, Y, K);
  auto f = [&](ll x) -> vi {
    vi A;
    while (x > 0) A.eb(x % K), x /= K;
    reverse(all(A));
    return A;
  };

  vi A = f(X);
  vi B = f(Y);
  SHOW(A, B);

  ll n = 0;
  while (n < len(A) && n < len(B) && A[n] == B[n]) ++n;
  ll ANS = len(A) + len(B) - 2 * n;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}