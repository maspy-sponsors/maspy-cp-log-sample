#include "my_template.hpp"
#include "other/io.hpp"

#include "alg/monoid/add.hpp"
#include "ds/unionfind/rollback_potentialized_unionfind.hpp"
#include "mod/dynamic_modint.hpp"

using mint = dmint;
void solve() {
  LL(N, mod, Q);
  mint::set_mod(mod);

  vc<tuple<ll, ll, ll, ll, ll>> dat(Q + 1);
  vvc<int> ch(Q + 1);

  FOR(q, 1, Q + 1) {
    LL(t, b, l, r);
    --l;
    if (t == 0) {
      LL(x);
      dat[q] = {t, b, l, r, x};
    } else {
      dat[q] = {t, b, l, r, 0};
    }
    ch[b].eb(q);
  }

  Rollback_Potentialized_UnionFind<Monoid_Add<mint>> uf(N + 1);

  vc<string> ANS(Q + 1);
  auto dfs = [&](auto &dfs, int v) -> void {
    for (int c : ch[v]) {
      auto [t, b, l, r, x] = dat[c];
      int time = uf.time();
      if (t == 1) {
        auto [ra, xa] = uf.get(l);
        auto [rb, xb] = uf.get(r);
        if (ra == rb) {
          ANS[c] = to_string((xb - xa).val);
        } else {
          ANS[c] = "UNKNOWN";
        }
      } else {
        auto [ra, xa] = uf.get(l);
        auto [rb, xb] = uf.get(r);
        if (ra != rb || (ra == rb && xb == xa + x)) {
          ANS[c] = "YES";
          uf.merge(l, r, x);
        } else {
          ANS[c] = "NO";
        }
      }
      dfs(dfs, c);
      uf.rollback(time);
    }
  };
  dfs(dfs, 0);
  FOR(q, 1, Q + 1) print(ANS[q]);
}

signed main() {
  solve();
  return 0;
}