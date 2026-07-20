#include "my_template.hpp"
#include "other/io.hpp"

/*

ABABA/ABABA/ABABA みたいなこと


you are allowed to do it, but you don't have to do it);
*/

void solve() {
  // LL(N);
  STR(S);
  ll N = len(S);
  vc<int> I;
  FOR(i, N - 1) if (S[i] == S[i + 1]) I.eb(i + 1);
  I.eb(0);
  I.eb(N);
  UNIQUE(I);

  if (len(I) >= 6) return NO();

  SHOW(I);

  for (auto &a : I) {
    for (auto &b : I) {
      if (a >= b) continue;
      string T = S;
      reverse(T.begin() + a, T.begin() + b);
      FOR(i, a, b) T[i] = 'a' + 'b' - T[i];
      bool ok = 1;
      FOR(i, N - 1) ok = ok && (T[i] != T[i + 1]);
      if (ok) return YES();
    }
  }
  for (auto &a : I) {
    for (auto &b : I) {
      if (a >= b) continue;
      string T = S;
      reverse(T.begin() + a, T.begin() + b);
      // FOR(i, a, b) T[i] = 'a' + 'b' - T[i];
      bool ok = 1;
      FOR(i, N - 1) ok = ok && (T[i] != T[i + 1]);
      if (ok) return YES();
    }
  }
  NO();
}

signed main() {
  INT(T);
  FOR(T) solve();
}