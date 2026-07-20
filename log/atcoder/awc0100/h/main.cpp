#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  VEC(ll, B, N);

  vvc<int> G(N);
  FOR(M) {
    INT(a, b);
    --a, --b;
    G[a].eb(b);
  }

  auto I = argsort(B);
  FOR(s, N) {
    sort(all(G[s]), [&](auto &a, auto &b) -> bool { return B[a] < B[b]; });
  }

  vi ANS;
  vi vis(N);

  auto work = [&](int s) -> void {
    if (vis[s]) return;
    int v = s;
    while (1) {
      ANS.eb(v);
      vis[v] = 1;
      while (len(G[v]) && vis[G[v].back()]) POP(G[v]);
      if (G[v].empty()) break;
      v = POP(G[v]);
    }
  };

  work(0);
  reverse(all(I));
  for (int v : I) work(v);

  for (auto &x : ANS) ++x;
  print(ANS);
}

signed main() {
  solve();
  return 0;
}