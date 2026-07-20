#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/hashmap.hpp"

ll F(ll N) {
  // 1 to N

  using ARR = array<ll, 10>;

  HashMap<ARR> MP;
  auto dfs = [&](auto& dfs, ll N) -> ARR {
    if (N == 0) return {};
    if (MP.count(N)) return MP[N];

    ARR ANS{};
    FOR(d, 10) {
      if (d > N) break;
      if (d > 0) ANS[d] += 1;
      ll X = floor<ll>(N - d, 10);
      ARR Y = dfs(dfs, X);
      FOR(i, 10) ANS[max(i, d)] += Y[i];
    }
    MP[N] = ANS;
    return ANS;
  };
  ARR X = dfs(dfs, N);
  ll ans = 0;
  FOR(i, 10) ans += i * X[i];
  return ans;
}

void solve() {
  LL(L, R);
  ll ANS = F(R) - F(L - 1);
  print(ANS);
}

void test() {
  ll ans = 0;
  FOR(N, 1, 1000) {
    string S = to_string(N);
    ll ma = MAX(S) - '0';
    ans += ma;
    ll me = F(N);
    SHOW(N, ans, me);
    assert(ans == me);
  }
}

signed main() {
  // test();
  INT(T);
  FOR(T) solve();
}