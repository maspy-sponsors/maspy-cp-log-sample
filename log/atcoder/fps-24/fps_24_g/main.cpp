#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N, M, L);
  vc<mint> f(N + 1);
  f[0] = 1;
  auto add = [&](int a) -> void { FOR(i, N - a + 1) f[i + a] += f[i]; };
  auto rm = [&](int a) -> void { FOR_R(i, N - a + 1) f[i + a] -= f[i]; };

  FOR(x, 1, L) add(x);
  FOR(x, L, M + 1) {
    add(x);
    print(f[N]);
    rm(x - L + 1);
  }
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}