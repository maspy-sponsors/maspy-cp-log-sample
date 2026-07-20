#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(K);
  FOR(N, 1, 1000) {
    ll X = K * N;
    string S = to_string(X);
    bool ok = 0;
    FOR(i, len(S) - 1) ok = ok || (S[i] == '0' && S[i + 1] == '0');
    if (ok) return print(X);
  }
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}
