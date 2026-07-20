#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/dynamic_modint.hpp"

using mint = dmint;

void solve() {
  LL(N, K, mod);
  ++K;
  dmint::set_mod(mod);

  ll LIM = (N - 1) * N / 2 * (K - 1);
  vc<mint> f(LIM + 1);
  ll off = 0;
  f[0] = 1;

  auto mul = [&](ll a) -> void {
    // (1-x^(Ka))/1-x^a
    FOR_R(i, LIM + 1) {
      if (i + K * a <= LIM) f[i + K * a] -= f[i];
    }
    FOR(i, LIM + 1) if (i + a <= LIM) f[i + a] += f[i];
  };

  auto div = [&](ll a) -> void {
    FOR(i, LIM + 1) {
      if (i + K * a <= LIM) f[i + K * a] += f[i];
    }
    FOR_R(i, LIM + 1) if (i + a <= LIM) f[i + a] -= f[i];
  };

  // mean = 0
  FOR(a, 1, N) { mul(a); }

  FOR(mean, N) {
    print(f[off] * mint(K) - mint(1));
    if (mean == N - 1) break;
    ll n = (N - 1) - mean;
    div(n);
    n = mean + 1;
    mul(n);
    off += n * (K - 1);
  }
}

signed main() {
  solve();
  return 0;
}
