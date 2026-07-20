#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "enumerate/set_partitioin.hpp"
#include "graph/base.hpp"
#include "graph/path_cycle.hpp"
#include "mod/modfast.hpp"

/*
本質：問題文にある最初の k は入力の k と無関係と思われる！！！！！

順列を固定した場合
[0] 0 回でできる：1通り
[1] 1 回でできる；1通り
[2] それ以外は必ず 2 回でできます

逆に初期状態から 2 回で作れるものは？と思うとわかりやすい
1 回目のマッチングを色 1 の辺
2 回目のマッチングを色 2 の辺
とすると、交互パスまたは交互サイクルに分解できる

[12121] 偶サイクル
[21212] 偶サイクル
[121212 path] 奇サイクル
[121212 cycle] 同じ長さのサイクル 2 つ !!

- 同じ長さのサイクルをいくつか組にしてまとめて処理できる
- それ以外のサイクル：適当な係数をかける

dp[cycle length][cycle count] は簡単に計算可能

入力は、サイクルとパスに分解されている
あとはベル数列挙
*/

using mint = modint107;

void solve() {
  LL(N, unused);
  // cycle len, cycle cnt
  vv(mint, dp, N + 1, 1, 1);

  FOR(n, 1, N + 1) {
    mint one = n;
    mint two = n;
    int mx = floor<int>(N, n);
    dp[n].resize(mx + 1);
    dp[n][0] = 1;
    FOR(k, 1, mx + 1) {
      dp[n][k] = dp[n][k - 1] * one;
      if (k >= 2) {
        dp[n][k] += dp[n][k - 2] * (k - 1) * two;
      }
      SHOW(n, k, dp[n][k]);
    }
  }
  VEC(int, A, N);
  for (auto &x : A) --x;

  Graph<int, 0> G(N);
  FOR(v, N) {
    int w = A[v];
    if (w != -1) G.add(v, w);
  }
  G.build();

  vc<int> P, C;
  auto [paths, cycs] = path_cycle(G);
  for (auto &V : paths) P.eb(len(V));
  for (auto &V : cycs) C.eb(len(V));

  vc<int> S(N + 1);
  for (auto &x : C) S[x]++;
  ModFast<mint::get_mod()> fast;
  auto segf = [&](int i) -> ll {
    // return dp[i][S[i]];
    return fast.log_r(dp[i][S[i]].val);
  };

  // SegTree<Monoid_Mul<mint>> seg(N + 1, segf);
  ll base = 0;
  FOR(x, N + 1) base += segf(x);

  int n = len(P);
  vc<int> SM(1 << n);
  FOR(i, n) FOR(s, 1 << i) SM[s | 1 << i] = SM[s] + P[i];

  mint ANS = 0;
  set_partition(n, [&](vc<int> A) -> void {
    SHOW(A);
    ll log_sm = base;
    mint cf = 1;
    for (auto &x : A) {
      cf *= fact<mint>(popcnt(x) - 1);

      log_sm -= segf(SM[x]);
      S[SM[x]]++;
      log_sm += segf(SM[x]);
    }
    mint ans = 0;
    if (S[1] == N) {
      ans = 1;
    }
    elif (S[1] + 2 * S[2] == N) { ans = 1; }
    else {
      // ans = seg.prod_all();
      ans = fast.pow_r(log_sm % (mint::get_mod() - 1));
    }
    ANS += cf * ans;
    for (auto &x : A) {
      S[SM[x]]--;
      // seg.set(SM[x], segf(SM[x]));
    }
  });
  print(ANS);
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}