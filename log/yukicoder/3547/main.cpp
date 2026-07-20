#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  ll ANS = 0;
  FOR(k, 30) {
    ll a = N >> k & 1;
    ll b = M >> k & 1;

    ll x = -1;

    FOR_R(c, 2) {
      ll d = (k % 2 == 0 ? (a & c) : (a | c));
      if (d == b) x = c;
    }
    if (x == -1) return print(-1);
    ANS += x << k;
  }
  print(ANS);
}

signed main() { solve(); }
