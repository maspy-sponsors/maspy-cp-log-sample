#include "my_template.hpp"
#include "other/io.hpp"
#include "poly/fps_exp.hpp"
using mint = modint998;

void solve() {
  LL(N);
  vc<mint> CNT(N + 1);
  FOR(i, 1, N + 1) {
    LL(a);
    ++a;
    CNT[i] -= 1;
    if (a * i <= N) {
      CNT[a * i] += 1;
    }
  }

  vc<mint> logf(N + 1);
  FOR(x, 1, N + 1) {
    FOR(d, 1, N / x + 1) { logf[d * x] -= CNT[x] * inv<mint>(d); }
  }

  vc<mint> f = fps_exp<mint>(logf);
  print(f[N]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}