#include "my_template.hpp"
#include "other/io.hpp"
#include "string/run_length.hpp"
#include "alg/monoid/min.hpp"
#include "ds/segtree/segtree.hpp"
#include "ds/segtree/dual_segtree.hpp"

/*
x to y
間の状況

なるべく配るか
-1 しかない遷移：i 側で配る
y しかない遷移：i 側で配る
x, y 両方：i 側で配る

x しかない遷移：j 側で受け取る
*/

void solve() {
  auto get = [&]() -> vc<int> {
    STR(S);
    return s_to_vi(S, '0');
  };
  vc<int> A = get(), B = get();
  {
    A.insert(A.begin(), 1 - A[0]);
    A.eb(1 - A.back());
    B.insert(B.begin(), A[0]);
    B.eb(A.back());

    if (A[0] == 1) {
      for (auto& x : A) x = 1 - x;
      for (auto& x : B) x = (x == -1 ? -1 : 1 - x);
    }
  }
  SHOW(A);
  SHOW(B);
  ll N = len(A);

  vc<int> cut = {0};
  for (auto& [k, x] : run_length(A)) {
    cut.eb(cut.back() + x);
  }
  ll n = len(cut) - 1;
  vc<int> dp(n, infty<int>);
  dp[0] = 0;
  vi good(n, 1);
  FOR(k, n) {
    FOR(i, cut[k], cut[k + 1]) {
      if (B[i] == 1 - (k % 2)) good[k] = 0;
    }
  }

  // {
  //   vc<int> dp(n, infty<int>);
  //   dp[0] = 0;
  //   vc<int> A0(N), A1(N), B0(N), B1(N);

  //   FOR(i, N) A0[i] += (A[i] == 0);
  //   FOR(i, N) A1[i] += (A[i] == 1);
  //   FOR(i, N) B0[i] += (B[i] == 0);
  //   FOR(i, N) B1[i] += (B[i] == 1);
  //   A0 = cumsum<int>(A0);
  //   A1 = cumsum<int>(A1);
  //   B0 = cumsum<int>(B0);
  //   B1 = cumsum<int>(B1);

  //   FOR(j, n) FOR(i, j) {
  //     if (!good[i]) continue;
  //     if (!good[j]) continue;
  //     if ((j - i) % 2 == 0) continue;
  //     int s = cut[i + 1], t = cut[j];
  //     bool ok = 0;
  //     if (i % 2 == 0) {
  //       int m = s + A0[t] - A0[s];
  //       ok = B1[m] - B1[s] == 0 && B0[t] - B0[m] == 0;
  //     } else {
  //       int m = s + A1[t] - A1[s];
  //       ok = B0[m] - B0[s] == 0 && B1[t] - B1[m] == 0;
  //     }
  //     if (ok) {
  //       chmin(dp[j], dp[i] + (j - i - 1) / 2);
  //     }
  //   }
  //   ll ANS = dp[n - 1];
  //   SHOW(dp);
  //   if (ANS == infty<int>) ANS = -1;
  // }

  // seg に入れるもの
  // 2 * dp[i] - i - 1
  vc<SegTree<Monoid_Min<int>>> seg(2);
  vc<Dual_SegTree<Monoid_Min<int>>> dseg(2);

  FOR(k, 2) seg[k].build(n);
  FOR(k, 2) dseg[k].build(n);
  vv(int, nxt, 2, N + 1, N);
  vv(int, pre, 2, N + 1, -1);
  FOR(i, N) if (B[i] != -1) nxt[B[i]][i] = i;
  FOR(i, N) if (B[i] != -1) pre[B[i]][i] = i;
  FOR(k, 2) FOR_R(j, N) chmin(nxt[k][j], nxt[k][j + 1]);
  FOR(k, 2) FOR(j, N) chmax(pre[k][j + 1], pre[k][j]);

  vv(int, CA, 2, N);
  vv(int, CB, 2, N);
  FOR(i, N) if (0 <= A[i]) CA[A[i]][i] = 1;
  FOR(i, N) if (0 <= B[i]) CB[B[i]][i] = 1;
  FOR(i, 2) CA[i] = cumsum<int>(CA[i]);
  FOR(i, 2) CB[i] = cumsum<int>(CB[i]);

  auto pull_x = [&](int j) -> void {
    int y = j % 2;
    int x = 1 - y;
    // i ...x  x  x  ... j
    int pos = pre[x][cut[j]];
    if (pos == -1) return;

    auto large = [&](int i) -> bool {
      // 十分大きいのは？
      // y が入ってこない
      if (cut[i + 1] <= pre[y][cut[j] - 1]) return false;
      // A 側に y が十分少ない
      int k = CA[y][cut[j]] - CA[y][cut[i + 1]];
      return k < cut[j] - pos;
    };

    auto small = [&](int i) -> bool {
      // 十分小さいという条件は？
      // pos が入っています
      return cut[i + 1] <= pos;
    };

    int l = binary_search(large, j, -1, 0);
    int r = binary_search(small, -1, j, 0);
    SHOW(j, l, r);
    if (l > r) return;
    int v = seg[x].prod(l, r + 1);
    if (v < infty<int>) chmin(dp[j], (v + j) / 2);
  };
  auto push = [&](int i) -> void {
    if (dp[i] == infty<int>) return;
    int x = i % 2, y = 1 - x;
    auto large = [&](int j) -> bool { return i < j; };
    auto small = [&](int j) -> bool {
      // ? だけしかありません
      if (nxt[0][cut[i + 1]] < cut[j]) return false;
      if (nxt[1][cut[i + 1]] < cut[j]) return false;
      return true;
    };
    int l = binary_search(large, n, i, 0);
    int r = binary_search(small, i, n, 0);
    if (l > r) return;
    SHOW(i, l, r);
    dseg[y].apply(l, r + 1, 2 * dp[i] - i - 1);
  };
  auto push_y = [&](int i) -> void {
    // y only
    if (dp[i] == infty<int>) return;
    int x = i % 2, y = 1 - x;
    int pos = nxt[y][cut[i + 1]];
    if (pos == N) return;
    auto large = [&](int j) -> bool {
      // pos はあります
      return pos < cut[j];
    };
    auto small = [&](int j) -> bool {
      // x はありません
      if (nxt[x][cut[i + 1]] < cut[j]) return false;
      // A 側の x は少ないです
      int k = CA[x][cut[j]] - CA[x][cut[i + 1]];
      if (pos < cut[i + 1] + k) return false;
      return true;
    };
    int l = binary_search(large, n, i, 0);
    int r = binary_search(small, i, n, 0);
    if (l > r) return;
    SHOW(i, l, r);
    dseg[y].apply(l, r + 1, 2 * dp[i] - i - 1);
  };

  auto push_xy = [&](int i) -> void {
    if (dp[i] == infty<int>) return;
    // [i]  x  x  y  y  y  [j]
    int x = i % 2, y = 1 - x;
    int q = nxt[y][cut[i + 1]];
    int p = pre[x][q];
    if (cut[i + 1] > p) return;
    auto large = [&](int j) -> bool {
      // q はあります
      if (cut[j] <= q) return false;
      // p までは x です
      int k = CA[x][cut[j]] - CA[x][cut[i + 1]];
      return p < cut[i + 1] + k;
    };
    auto small = [&](int j) -> bool {
      // p の次はありません
      if (cut[j] > nxt[x][p + 1]) return false;
      // q は y です
      int k = CA[x][cut[j]] - CA[x][cut[i + 1]];
      return cut[i + 1] + k <= q;
    };
    int l = binary_search(large, n, i, 0);
    int r = binary_search(small, i, n, 0);
    if (l > r) return;
    SHOW(i, l, r, p, q);
    dseg[y].apply(l, r + 1, 2 * dp[i] - i - 1);
  };
  FOR(i, n) {
    if (!good[i]) continue;
    int x = dseg[i % 2].get(i);
    if (x < infty<int>) chmin(dp[i], (x + i) / 2);
    pull_x(i), push(i), push_y(i), push_xy(i);
    seg[i % 2].set(i, 2 * dp[i] - i - 1);
  }
  SHOW(dp);
  ll ANS = dp[n - 1];
  if (ANS == infty<int>) ANS = -1;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}