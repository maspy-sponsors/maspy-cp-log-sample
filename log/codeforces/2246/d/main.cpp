#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  SHOW(A);

  auto F = [&](ll a) -> ll { return popcnt(a) + topbit(a); };

  ll ANS = infty<ll>;

  SHOW(A);
  FOR(K, 32) {
    vi S(N, infty<int>);
    vi T(N, infty<int>);
    ll bit = 1LL << K;
    FOR(i, N) {
      ll a = A[i];
      ll b = ceil<ll>(a, bit) * bit;
      FOR(x, 60) {
        if (bit * x > ANS) break;
        ll c = b + bit * x;
        ll v = F(c);
        chmin(S[i], v + c - a);
        if (c % (2 * bit) != 0) chmin(T[i], v + c - a);
      }
    }
    SHOW(K, S, T);
    ll sm = SUM<ll>(S);
    FOR(i, N) {
      ll val = sm - S[i] + T[i];
      chmin(ANS, val - K * (N - 1));
    }
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}
