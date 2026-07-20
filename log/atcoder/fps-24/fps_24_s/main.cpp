#include "my_template.hpp"
#include "other/io.hpp"

#include "poly/online/online_exp.hpp"
#include "enumerate/labeled_tree.hpp"

using mint = modint998;

void sol1(ll N) {
  vc<mint> F(N + 1);  // lose
  vc<mint> G(N + 1);  // win
  F[1] = 1;
  Online_Exp<mint> E;
  E.query(0, 0);

  FOR(n, 2, N + 1) {
    // auto tmp = fps_exp<mint>(G);
    // F[n] = tmp[n - 1];
    F[n] = E.query(n - 1, G[n - 1]);
    mint T = mint(n).pow(n - 1);  // rooted
    G[n] = T * fact_inv<mint>(n) - F[n];
  }

  FOR(i, N + 1) F[i] *= fact<mint>(i);
  FOR(i, N + 1) G[i] *= fact<mint>(i);

  FOR(n, 2, N + 1) print(F[n] * inv<mint>(n));  // root
}

void test() {
  FOR(N, 1, 10) {
    ll ANS = 0;
    enumerate_labeled_tree(N, [&](vc<pair<int, int>> edges) {
      Graph<int, 0> G(N);
      for (auto& [a, b] : edges) G.add(a, b);
      G.build();
      // lose?
      auto dfs = [&](auto& dfs, int v, int p) -> int {
        for (auto& e : G[v]) {
          if (e.to == p) continue;
          if (dfs(dfs, e.to, v) == 0) return 1;
        }
        return 0;
      };
      FOR(r, N) {
        if (!dfs(dfs, r, -1)) return;
      }
      // lose
      // G.debug();
      ++ANS;
      // print();
    });
    print(ANS);
  }
}

/*
奇数頂点だと勝ってしまうのか？なんでですか？？？？
それはそうか
*/
void solve() {
  LL(N, tp);
  if (tp == 1) {
    return sol1(N);
  }

  FOR(n, 2, N + 1) {
    mint ANS = mint(n).pow(n - 2);
    if (n % 2 == 0) {
      ANS -= mint(n).pow(n / 2 - 2) * fact<mint>(n) * fact_inv<mint>(n / 2);
    }
    print(ANS);
  }
}

int main() {
  // test();
  // return 0;
  // INT(T);
  // FOR(T)
  solve();
}