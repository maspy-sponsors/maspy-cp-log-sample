#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/hashmap.hpp"

/*
次数が小さい方から大きい方に有向辺をはる（出次数が小さい）
FRM -> TO
ANS[TO] に FRM の情報を反映された状態を保つ
ANS[FRM] に TO の情報は反映しないでおく（とりにいく）
*/

void solve() {
  LL(N, M, Q);
  vc<int> FRM, TO, ACTIVE;
  vc<int> deg(N);
  vvc<int> EID(N);
  vc<int> ANS(N);

  HashMap<int> MP;
  auto edge_idx = [&](int a, int b) -> int {
    if (a > b) swap(a, b);
    u64 k = u64(a) << 32 | b;
    if (MP.count(k)) return MP[k];
    int eid = len(FRM);
    MP[k] = eid;
    if (deg[a] > deg[b]) swap(a, b);
    deg[a]++, deg[b]++;
    FRM.eb(a), TO.eb(b);
    ACTIVE.eb(0);
    EID[a].eb(eid);
    return eid;
  };

  vc<int> ONLINE(N);
  {
    INT(n);
    FOR(n) {
      INT(v);
      ONLINE[--v] = 1;
    }
  }

  auto add = [&](int a, int b) -> void {
    int eid = edge_idx(a, b);
    assert(!ACTIVE[eid]);
    ACTIVE[eid] = 1;
    ANS[TO[eid]] += ONLINE[FRM[eid]];
  };

  auto rm = [&](int a, int b) -> void {
    int eid = edge_idx(a, b);
    assert(ACTIVE[eid]);
    ACTIVE[eid] = 0;
    ANS[TO[eid]] -= ONLINE[FRM[eid]];
  };

  auto login = [&](int v) -> void {
    assert(!ONLINE[v]);
    ONLINE[v] = 1;
    for (auto &eid : EID[v]) {
      ANS[TO[eid]] += ACTIVE[eid];
    }
  };

  auto logout = [&](int v) -> void {
    assert(ONLINE[v]);
    ONLINE[v] = 0;
    for (auto &eid : EID[v]) {
      ANS[TO[eid]] -= ACTIVE[eid];
    }
  };

  auto solve = [&](int v) -> int {
    int ans = ANS[v];
    for (auto &eid : EID[v]) {
      if (ACTIVE[eid]) ans += ONLINE[TO[eid]];
    }
    return ans;
  };

  FOR(M) {
    INT(a, b);
    --a, --b;
    add(a, b);
  }

  FOR(Q) {
    STR(S);
    if (S == "O") {
      INT(v);
      login(--v);
    }
    if (S == "F") {
      INT(v);
      logout(--v);
    }
    if (S == "A") {
      INT(a, b);
      --a, --b;
      add(a, b);
    }
    if (S == "D") {
      INT(a, b);
      --a, --b;
      rm(a, b);
    }
    if (S == "C") {
      INT(v);
      --v;
      print(solve(v));
    }
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}