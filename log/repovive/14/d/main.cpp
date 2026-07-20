#include "my_template.hpp"
#include "other/io.hpp"
#include "nt/rational.hpp"
#include "mod/modint.hpp"
#include "graph/shortest_path/bfs01.hpp"

using QT = Rational<ll>;

void solve() {
  LL(N, M);
  Graph<int, 0> G(N);
  G.read_graph(M);
  auto D = bfs01<int>(G, N - 1).fi;

  QT ANS = QT(D[0], 1);

  vi X(N + 1);
  vi Y(N + 1);
  for (auto &x : D) X[x]++, Y[x] += x;

  auto Xc = cumsum<ll>(X);
  auto Yc = cumsum<ll>(Y);

  FOR(K, 1, D[0] + 1) {
    // 距離 K 以上の間とびつづける
    ll good = Xc[K];
    // N/good
    QT ans = QT(N, good);
    ans += QT(Yc[K], good);
    ANS = min(ANS, ans);
  }
  // print(ANS.to_string());
  using mint = modint998;
  mint ans = mint(ANS.num) / ANS.den;
  print(ans);
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}