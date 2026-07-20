#include "my_template.hpp"
#include "other/io.hpp"

#include "other/mex.hpp"

void solve() {
  // time -> value
  LL(N, M);
  VEC(ll, A, N);
  vvc<int> dat(M + 1);

  FOR(i, N) {
    // 0 <= A[i] + (i+1) x <= N
    ll lo = ceil(-A[i], i + 1);
    ll hi = floor(N - A[i], i + 1);
    FOR(t, lo - 5, hi + 5) {
      if (1 <= t && t <= M) {
        ll x = A[i] + (i + 1) * t;
        if (0 <= x && x <= N) {
          dat[t].eb(x);
        }
      }
    }
  }

  vc<int> used(N + 1);
  FOR(m, 1, M + 1) { print(mex(dat[m])); }
}

signed main() {
  solve();
  return 0;
}
