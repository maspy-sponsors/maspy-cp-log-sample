#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  sort(all(A));
  map<ll, ll> MP;
  for (auto& x : A) MP[x]++;
  vi cand;
  for (auto& [a, b] : MP)
    if (b >= 2) cand.eb(a);

  reverse(all(cand));
  while (len(cand) > 5) POP(cand);

  for (auto& c : cand) {
    MP[c] -= 2;
    vi B;
    for (auto& [a, b] : MP) {
      FOR(b) B.eb(a);
    }
    MP[c] += 2;
    FOR(i, len(B) - 1) {
      ll a = B[i], b = B[i + 1];
      if (c + a + c > b) return print(c, c, a, b);
    }
  }
  print(-1);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}