#include "my_template.hpp"
#include "other/io2.hpp"
#include "random/hash_pair.hpp"
#include "ds/hashmap.hpp"
#include "convex/smawk.hpp"

int ask(int i, int j) {
#if defined(LOCAL)
  vv(int, A, 5, 5);
  A[0] = {13, 15, 10, 9, 15};
  A[1] = {15, 17, 12, 11, 17};
  A[2] = {10, 12, 7, 6, 12};
  A[3] = {17, 19, 14, 13, 19};
  A[4] = {16, 18, 13, 12, 18};
  return A[i][j];
#endif
  static HashMap<int, 23> MP;
  u64 k = hash_pair<int>({i, j});
  if (MP.count(k)) return MP[k];
  print("?", 1 + i, 1 + j);
  INT(x);
  MP[k] = x;
  return x;
}

void solve() {
  INT(H, W);
  vc<int> I = smawk(
      H, W, [&](int i, int j, int k) -> bool { return ask(i, j) > ask(i, k); });

  int ANS = infty<int>;
  FOR(i, H) chmin(ANS, ask(i, I[i]));
  print("!", ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}