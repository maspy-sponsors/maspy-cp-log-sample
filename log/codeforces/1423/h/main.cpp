#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/unionfind/rollback_unionfind.hpp"
#include "ds/rollback_array.hpp"
#include "ds/offline_query/add_remove_query.hpp"

void solve() {
  LL(N, Q, K);
  vvc<tuple<int, int, int>> edge(Q);
  vc<int> QUERY;
  Add_Remove_Query<tuple<int, int, int>, true> X;
  int day = 0;
  FOR(q, Q) {
    INT(t);
    if (t == 1) {
      INT(a, b);
      --a, --b;
      tuple<int, int, int> e = {q, a, b};
      edge[day].eb(e);
      X.add(len(QUERY), e);
    }
    if (t == 2) {
      INT(z);
      QUERY.eb(--z);
    }
    if (t == 3) {
      ++day;
      if (day >= K) {
        for (auto &e : edge[day - K]) X.remove(len(QUERY), e);
      }
    }
  }

  // rollback_dfs
  auto upd = X.calc(len(QUERY));
  vi ANS(len(QUERY));
  vc<int> I(len(upd));
  iota(all(I), 0);
  Rollback_UnionFind uf(N);
  Rollback_Array<int> A(N);
  FOR(i, N) A.set(i, 1);

  auto dfs = [&](auto &dfs, vc<int> &upd_query_I, int begin, int end) -> void {
    if (begin == end) return;
    // snapshot
    int uf_time = uf.time();
    int A_time = A.time();
    vc<int> IL, IR;
    int mid = (begin + end) / 2;
    for (auto &&i : upd_query_I) {
      auto [a, b, X] = upd[i];
      if (a <= begin && end <= b) {
        // X で表される update query を処理する
        auto [q, u, v] = X;
        u = uf[u], v = uf[v];
        if (u != v) {
          uf.merge(u, v);
          int w = uf[u];
          A.set(w, A.get(u) + A.get(v));
        }
      } else {
        if (a < mid) IL.eb(i);
        if (mid < b) IR.eb(i);
      }
    }
    if (begin + 1 == end) {
      // 求値クエリ
      int qid = begin;
      int z = QUERY[qid];
      print(A.get(uf[z]));
    } else {
      dfs(dfs, IL, begin, mid);
      dfs(dfs, IR, mid, end);
    }
    // rollback
    uf.rollback(uf_time);
    A.rollback(A_time);
  };
  dfs(dfs, I, 0, len(QUERY));
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}