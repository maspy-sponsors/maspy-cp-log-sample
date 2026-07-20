#include "my_template.hpp"
#include "other/io2.hpp"

#include "random/base.hpp"

/*
パスを作っていく
逆の色が出たらよけておく
*/

void solve() {
  LL(N);
  ll K = (N + 1) / 3;

  map<pair<int, int>, int> MP;

#ifdef LOCAL
  vv(int, adj, N, N);
  FOR(b, N) FOR(a, N) {
    int x = RNG(0, 2);
    adj[a][b] = adj[b][a] = x;
  }
#endif

  int QLE = 0;

  auto F = [&](int a, int b) -> int {
    assert(a != b);
    if (a > b) swap(a, b);
    pair<int, int> p = {a, b};
    if (MP.count(p)) return MP[p];
    ++QLE;
#ifdef LOCAL
    int x = adj[a][b];
    print("query", a, b, x);
    MP[p] = x;
    return x;
#else
    // ask
    print("?", 1 + a, 1 + b);
    INT(x);
    MP[p] = x;
    return x;
#endif
  };

  print(K);

  vc<tuple<int, int, int>> A;
  vc<int> path;
  FOR(v, N) {
    if (len(path) <= 1) {
      path.eb(v);
      continue;
    }
    int a = path[len(path) - 2];
    int b = path[len(path) - 1];
    int c = v;
    int x = F(a, b), y = F(b, c);
    if (x == y) {
      path.eb(v);
      continue;
    }
    A.eb(a, b, c);
    POP(path), POP(path);
  }

  vc<int> out;
  int p = (len(path) >= 2 ? F(path[0], path[1]) : 0);

  while (len(path) >= 2) {
    int a = POP(path);
    int b = POP(path);
    assert(F(a, b) == p);
    out.eb(a);
    out.eb(b);
  }
  for (auto &[a, b, c] : A) {
    if (F(a, b) == p) {
      out.eb(a);
      out.eb(b);
    } else {
      assert(F(b, c) == p);
      out.eb(b);
      out.eb(c);
    }
  }
  assert(len(out) >= 2 * K);
  out.resize(2 * K);

#ifdef LOCAL
  assert(QLE <= N);
  FOR(k, K) {
    int a = out[2 * k], b = out[2 * k + 1];
    assert(F(a, b) == p);
  }
#endif

  for (auto &x : out) ++x;
  print("!", out);
}

signed main() {
  INT(T);
  FOR(T) solve();
}