#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"

using mint = modint998;

void solve() {
  LL(N);
  // 1 + N +
  mint ANS = 1 + N;
  mint x = N * (N - 1) / 2;
  ANS += x / 3;
  print(ANS);
}

signed main() { solve(); }
