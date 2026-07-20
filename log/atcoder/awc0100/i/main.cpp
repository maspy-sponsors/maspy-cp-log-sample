#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/fenwicktree/fenwicktree_01.hpp"

void solve() {
  LL(N, M, S);

  FenwickTree_01 bit(N);
  FOR(i, N) bit.add(i);

  --S;
  FOR(M) {
    // S 覗く
    bit.remove(S);
    LL(d);
    --d;
    ll k = bit.sum(0, S);
    k = (k + d) % bit.sum_all();
    S = bit.kth(k);
  }
  print(1 + S);
}

signed main() {
  solve();
  return 0;
}