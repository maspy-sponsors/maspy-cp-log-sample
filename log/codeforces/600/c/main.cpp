#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  STR(S);
  ll N = S.size();
  auto A = s_to_vi(S, 'a');
  vi CNT(26);
  for (auto& x : A) CNT[x]++;
  vi ODD;
  FOR(x, 26) if (CNT[x] % 2 == 1) ODD.eb(x);
  ll n = ODD.size();
  FOR(i, n / 2) {
    ll x = ODD[i];
    ll y = ODD[n - 1 - i];
    CNT[y] -= 1;
    CNT[x] += 1;
  }
  string L, R;
  FOR(x, 26) {
    while (CNT[x] >= 2) {
      L += 'a' + x;
      R += 'a' + x;
      CNT[x] -= 2;
    }
  }
  FOR(x, 26) {
    if (CNT[x] == 1) L += 'a' + x;
  }
  reverse(all(R));
  print(L + R);
}

signed main() {
  solve();

  return 0;
}