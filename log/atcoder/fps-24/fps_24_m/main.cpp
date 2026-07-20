#include "my_template.hpp"
#include "other/io.hpp"
#include "mod/modint.hpp"
#include "graph/count/count_labeled_connected.hpp"

using mint = modint998;
void solve() {
  LL(N);
  auto A = count_labeled_connected<mint>(N);
  print(A[N]);
}

int main() {
  // INT(T);
  // FOR(T)
  solve();
}