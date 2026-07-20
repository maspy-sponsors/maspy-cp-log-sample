#include "my_template.hpp"
#include "other/io.hpp"

#include "string/suffix_array.hpp"
#include "alg/monoid/min.hpp"

void solve() {
  LL(N);
  STR(S, T);
  string ST = S + S + T + T;
  Suffix_Array X(ST);
  auto SA = X.SA;
  auto LCP = X.LCP;

  SegTree<Monoid_Min<int>> seg(LCP);
  vc<int> A(4 * N);
  FOR(i, 4 * N) A[i] = SA[i] < N;
  auto Ac = cumsum<int>(A);

  ll ANS = 0;
  FOR(i, len(ST)) {
    if (SA[i] < 2 * N || 3 * N <= SA[i]) continue;
    // SA[i] は T 由来の suffix
    auto check = [&](auto e) -> bool { return e >= N; };
    ll j = seg.max_right(check, i) + 1;
    // [i, j) のうち S に属するもの
    ANS += Ac[j];
  }
  print(ANS);
}

signed main() {
  solve();

  return 0;
}
