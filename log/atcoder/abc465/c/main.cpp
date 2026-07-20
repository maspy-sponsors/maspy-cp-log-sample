#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  bool rev = 0;
  deque<ll> D;
  STR(S);
  FOR(i, N) {
    ll x = i + 1;
    if (rev) {
      D.push_front(x);
    } else {
      D.push_back(x);
    }
    if (S[i] == 'o') rev ^= 1;
  }

  vi A(all(D));
  if (rev) reverse(all(A));
  print(A);
}

signed main() {
  solve();
  return 0;
}
