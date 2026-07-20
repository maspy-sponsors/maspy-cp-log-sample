#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/convolution.hpp"
#include "mod/modint.hpp"

using mint = modint998;

// ちょうどそこに止まる確率

void solve() {
  LL(N, M, L);
  vc<int> NG(N + 1);
  vc<mint> DICE(N + 1);
  FOR(M) {
    INT(a);
    DICE[a] = inv<mint>(M);
  }

  FOR(L) {
    INT(b);
    NG[b] = 1;
  }

  vc<mint> dp(N + N + 1);
  dp[0] = 1;
  auto dfs = [&](auto &dfs, int L, int R) -> void {
    if (R - L <= 1) return;
    // [L,M) to [M,R)
    int M = (L + R) / 2;
    dfs(dfs, L, M);

    vc<mint> f(M - L);
    FOR(i, L, M) {
      if (i < N && !NG[i]) {
        f[i - L] = dp[i];
      }
    }
    vc<mint> g(R - L);
    FOR(i, R - L) g[i] = (i < len(DICE) ? DICE[i] : 0);
    f = convolution<mint>(f, g);

    FOR(i, M, R) { dp[i] += f[i - L]; }

    dfs(dfs, M, R);
  };
  dfs(dfs, 0, N + N + 1);
  // print(dp);
  mint ANS = 1;
  FOR(i, N + 1) if (NG[i]) ANS -= dp[i];
  print(ANS);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}