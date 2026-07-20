#include "my_template.hpp"
#include "other/io.hpp"

#include "graph/base.hpp"

/*
予想
すべての頂点が偶数の状態で相手に渡すと勝てるということ
奇数が根だと勝てる
たぶんok


求めたい
odd, even, ..., even, odd
*/

void solve() {
  LL(N);
  Graph<int, 0> G(N);
  G.read_tree();

  ll ANS = 0;
  auto dfs = [&](auto &dfs, int v, int p) -> ll {
    ll me = G.deg(v) % 2;
    ll now = 0;
    for (auto &e : G[v]) {
      if (e.to == p) continue;
      ll x = dfs(dfs, e.to, v);
      if (me == 0) {
        ANS += now * x;
      } else {
        ANS += x;
      }
      now += x;
    }
    if (me == 0) {
      return now;
    } else {
      return 1;
    }
  };
  dfs(dfs, 0, -1);
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}