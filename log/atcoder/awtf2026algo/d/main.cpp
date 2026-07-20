#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/segtree/segtree.hpp"
#include "alg/monoid/min.hpp"
#include "alg/monoid/max.hpp"

// L_max まで進めたあと一回戻る必要あるけど，巻き戻すのは大変なので 2-pass 実装

struct Data {
  int N, Z;
  vc<int> P, Q, pos, X;
  vc<int> A;
  vc<int> st;

  // k -> pos[A[k]]
  SegTree<Monoid_Min<int>> seg;

  // value -> position if unused
  SegTree<Monoid_Min<int>> seg_pos_mi;
  SegTree<Monoid_Max<int>> seg_P_ma;

  Data(vc<int> &P, vc<int> &Q) : P(P), Q(Q) {
    N = len(P);
    Z = -1;
    pos.resize(N), X.resize(N);
    FOR(i, N) pos[P[i]] = i;
    FOR(i, N) X[i] = pos[Q[i]];

    seg.build(N);
    seg_pos_mi.build(pos);
    seg_P_ma.build(P);
  }

  bool used(int x) { return seg_pos_mi.get(x) == infty<int>; }

  pair<int, int> info(int k) {
    assert(k + 1 < len(A));
    int h = seg.prod(k, len(A));
    int w = A[k + 1];
    return {h, w};
  }

  void normalize() {
    while (len(st) >= 2) {
      int k1 = st[len(st) - 2];
      int k2 = st[len(st) - 1];
      auto [h1, w1] = info(k1);
      auto [h2, w2] = info(k2);
      assert(h1 <= h2);
      if (w1 <= w2) {
        st.pop_back();
        continue;
      }
      if (h1 < h2) break;
      st.pop_back();
      st.pop_back();
      st.eb(k2);
    }
  }

  bool exist_unused(int w, int h) {
    // x < w, pos[x] < h
    return seg_pos_mi.prod(0, w) < h;
  }

  /*
  A[L] を決めたあと残りを X 降順で追加した場合に valid になるかどうか判定する
  0: OK
  1: ng, type 1
  2: ng, type 2
  */
  int add_dryrun(int x) {
    int i = len(A);

    // type 1
    if (i > 0 && Z == -1) {
      int y = A.back();
      // ..., y, x
      if (y > x && pos[y] < pos[x]) {
        if (!exist_unused(x, pos[y])) return 1;
      }
    }

    // type 2
    if (!st.empty()) {
      auto [h, w] = info(st.back());
      if (pos[x] < h && w < x && !exist_unused(w, pos[x])) return 2;
    }
    return 0;
  }

  // 実際に追加する
  void add(int x) {
    int i = len(A);

    // x で解決するものは pop
    while (len(st)) {
      int k = st.back();
      auto [h, w] = info(k);
      if (pos[x] <= h && x < w) {
        st.pop_back();
      } else {
        break;
      }
    }

    A.eb(x);
    seg.set(i, pos[x]);
    seg_pos_mi.set(x, infty<int>);
    seg_P_ma.set(pos[x], -infty<int>);
    normalize();

    if (i > 0 && Z == -1) {
      int y = A[i - 1];
      if (y > x && pos[y] > pos[x]) {
        Z = i - 1;
      }
      if (y > x && pos[y] < pos[x]) {
        st.eb(i - 1);
        normalize();
      }
    }
  }

  int find_greedy() {
    int p = 0;
    // P での p 番目以降からとる

    if (!st.empty()) {
      auto [h, w] = info(st.back());
      p = seg_pos_mi.prod(0, w);
      assert(p < infty<int>);
    }
    int x = seg_P_ma.prod(p, N);
    assert(!used(x));
    // assert(add_dryrun(x) == 0);
    return x;
  }
};

vc<int> solve_lcp_zero(vc<int> P, vc<int> Q) {
  int N = len(P);

  if (N == 0) return {};

  auto [Lmax, tp] = [&]() -> pair<int, int> {
    Data X(P, Q);
    FOR(i, N) {
      int t = X.add_dryrun(Q[i]);
      if (t == 0) {
        X.add(Q[i]);
      } else {
        return {i, t};
      }
    }
    return {N, 0};
  }();

  if (Lmax == N) return Q;
  assert(tp == 1 || tp == 2);

  int L = (tp == 1 ? Lmax - 1 : Lmax);

  Data X(P, Q);
  FOR(i, L) X.add(Q[i]);

  int nxt = Q[L] - 1;
  while (X.used(nxt) || X.add_dryrun(nxt) != 0) --nxt;
  X.add(nxt);
  ++L;

  while (L < N) {
    int x = X.find_greedy();
    X.add(x);
    ++L;
  }
  return X.A;
}

void solve() {
  LL(N);
  VEC(int, P, N);
  VEC(int, Q, N);
  for (auto &x : P) --x;
  for (auto &x : Q) --x;

  int lcp = 0;
  while (lcp < N && P[lcp] == Q[lcp]) ++lcp;
  vc<int> ANS = {P.begin(), P.begin() + lcp};
  P = {P.begin() + lcp, P.end()};
  Q = {Q.begin() + lcp, Q.end()};

  vc<int> lb(N + 1);
  for (auto &x : P) lb[x + 1]++;
  FOR(i, N) lb[i + 1] += lb[i];
  vc<int> S;
  FOR(i, N) if (lb[i] < lb[i + 1]) S.eb(i);

  for (auto &x : P) x = lb[x];
  for (auto &x : Q) x = lb[x];
  Q = solve_lcp_zero(P, Q);
  for (auto &x : Q) ANS.eb(S[x]);

  for (auto &x : ANS) ++x;
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}
