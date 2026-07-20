#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, M);

  map<ll, ll> MP;
  for (auto &x : A) MP[x]++;

  ll split = 0;

  auto dfs = [&](auto &dfs, ll b) -> void {
    if (split > N) {
      split = infty<ll>;
      return;
    }
    if (MP.count(b)) {
      --MP[b];
      if (MP[b] == 0) MP.erase(b);
      return;
    }
    if (b == 0) {
      split = infty<ll>;
      return;
    }
    ++split;
    dfs(dfs, floor<ll>(b, 2));
    dfs(dfs, ceil<ll>(b, 2));
  };

  for (auto &b : B) dfs(dfs, b);
  if (M + split > N) return No();
  for (auto &[a, b] : MP)
    if (b != 0) return No();
  Yes();
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}