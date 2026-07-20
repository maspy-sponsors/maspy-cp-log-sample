#include "my_template.hpp"
#include "other/io.hpp"
#include "other/exp_search.hpp"

int EVEN, ODD;
void init() {
  FOR(i, 30) { (i % 2 == 0 ? EVEN : ODD) |= 1 << i; }
}

int f(int x, int y) {
  int x0 = x & EVEN;
  int x1 = x & ODD;
  int y0 = y & EVEN;
  int y1 = y & ODD;
  return (x0 & y0) | (x1 | y1);
}

void test() {
  int M = 1 << 15;
  vi G(M);
  vc<int> MP(M);
  FOR(N, 1, M) {
    FOR(y, N - 1) MP[f(N - 1, y)] += 2;
    MP[f(N - 1, N - 1)] += 1;
    int ans = max_element(all(MP)) - MP.begin();
    G[N] = ans;
  }
  int L = 0;
  for (auto &[ans, cnt] : run_length(G)) {
    int R = L + cnt;
    string S;
    FOR(i, 15) S += (has_kth_bit(ans, i) ? '1' : '0');
    reverse(all(S));
    print(S, ans, L, R);
    L = R;
  }
}

/*
まあふつうに、区分的に定数ということだと思われる
000000000000000 0 0 3
000000000000010 2 3 11
000000000001010 10 11 43
000000000101010 42 43 172
000000010101010 170 172 687
000001010101010 682 687 2746
000101010101010 2730 2746 10984
010101010101010 10922 10984 32768

結局、1010 型ということ
これの回数が求まればよい
*/

ll F(ll N, ll K) {
  if (K >= 16) return 0;
  if (N == 0) return 0;

  map<tuple<ll, ll, ll>, ll> MP;
  auto dfs = [&](auto &dfs, ll X, ll Y, int p) -> ll {
    // [0,N]
    if (p == 60) {
      assert(X == 0 && Y == 0);
      return 1;
    }

    tuple<ll, ll, ll> key = {X, Y, p};
    if (MP.count(key)) return MP[key];

    ll ANS = 0;
    FOR(a, 2) FOR(b, 2) {
      if (X < a || Y < b) continue;
      if (p % 2 == 0) {
        // AND = 0
        if ((a & b) != 0) continue;
      }
      if (p % 2 == 1 && p < 2 * K) {
        // OR = 1
        if ((a | b) == 0) continue;
      }
      if (p % 2 == 1 && p >= 2 * K) {
        // OR = 0
        if ((a | b) == 1) continue;
      }
      ll x = floor<ll>(X - a, 2);
      ll y = floor<ll>(Y - b, 2);
      ANS += dfs(dfs, x, y, p + 1);
    }
    return MP[key] = ANS;
  };
  ll ANS = dfs(dfs, N - 1, N - 1, 0);

  // ll v = 0;
  // FOR(i, K) v |= 1LL << (2 * i + 1);
  // ll god = 0;
  // FOR(x, N) FOR(y, N) { god += (f(x, y) == v); }
  // SHOW(N, K, god, ANS);
  // assert(god == ANS);
  return ANS;
}

void solve() {
  LL(N);
  ++N;
  ll K = 0;
  ll L = 0;

  ll ANS = 0;
  while (L < N) {
    // ll R = L;
    // while (F(R, K) >= F(R, K + 1)) {
    //   ++R;
    // }
    ll R =
        1 + exp_search([&](ll N) -> bool { return F(N, K) >= F(N, K + 1); }, L);
    chmin(R, N);
    ll v = 0;
    FOR(i, K) v |= 1LL << (2 * i + 1);
    ANS += v * (R - L);
    L = R;
    ++K;
  }
  print(ANS);
}

signed main() {
  init();
  // test();
  solve();
}
