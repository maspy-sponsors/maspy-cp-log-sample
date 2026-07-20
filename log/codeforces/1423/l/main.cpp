#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"
#include "random/base.hpp"

void solve() {
  LL(N, S, D);
  vc<u64> hash_base(N);
  FOR(i, N) hash_base[i] = RNG_64();

  vc<u64> dat;
  FOR(S) {
    u64 x = 0;
    LL(n);
    FOR(n) {
      INT(k);
      x ^= hash_base[k - 1];
    }
    dat.eb(x);
  }

  auto calc = [&](int L, int R) -> vc<u64> {
    int n = R - L;
    vc<u64> dp(1 << n);
    FOR(i, n) { FOR(s, 1 << i) dp[s ^ 1 << i] = dp[s] ^ dat[L + i]; }
    return dp;
  };

  int M = S / 2;

  auto dp1 = calc(0, M);
  auto dp2 = calc(M, S);
  HashMap<int> MP;
  FOR(s, len(dp2)) {
    u64 k = dp2[s];
    if (!MP.count(k)) MP[k] = infty<int>;
    chmin(MP[k], popcnt(s));
  }

  FOR(D) {
    ll ANS = infty<int>;
    u64 H = 0;
    INT(n);
    FOR(n) {
      INT(k);
      H ^= hash_base[k - 1];
    }
    FOR(s, len(dp1)) {
      u64 k = dp1[s] ^ H;
      ll cost = MP.get(k, infty<int>);
      chmin(ANS, popcnt(s) + cost);
    }
    if (ANS == infty<int>) ANS = -1;
    print(ANS);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}