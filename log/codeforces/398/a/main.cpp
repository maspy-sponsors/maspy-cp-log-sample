#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(a, b);
  const ll INF = 1LL << 60;
  auto f = [&](ll x, ll y) -> ll {
    if (a < x) return -INF;
    if (b < y) return -INF;
    if (a > 0 && x == 0) return -INF;
    if (b > 0 && y == 0) return -INF;
    if (abs(x - y) > 1) return -INF;
    if (x == 0) return -b * b;
    if (y == 0) return a * a;
    ll val = 0;
    val += 1 * (x - 1) + (a - x + 1) * (a - x + 1);
    ll q = b / y, r = b % y;
    val -= (q + 1) * (q + 1) * r + q * q * (y - r);
    return val;
  };

  ll ANS = -INF;
  pi best = {0, 0};
  FOR(k, 1 << 17) {
    if (chmax(ANS, f(k, k))) best = {k, k};
    if (chmax(ANS, f(k, k + 1))) best = {k, k + 1};
    if (chmax(ANS, f(k + 1, k))) best = {k + 1, k};
  }

  print(ANS);

  auto [x, y] = best;
  if (y == 0) {
    string S;
    S.assign(a, 'o');
    return print(S);
  }

  vi A(x), B(y);
  FOR(i, x) A[i] = 1;
  if (x) A[0] = a - x + 1;
  ll q = b / y, r = b % y;
  FOR(i, y) B[i] = q;
  FOR(i, r) B[i]++;

  auto make_str = [&](char a, vi A, char b, vi B) -> string {
    if (len(A) < len(B)) {
      swap(A, B);
      swap(a, b);
    }
    string S;
    while (len(A)) {
      FOR(_, A.back()) S += a;
      A.pop_back();
      if (len(B)) {
        FOR(_, B.back()) S += b;
        B.pop_back();
      }
    }
    return S;
  };

  print(make_str('o', A, 'x', B));
}

signed main() {
  solve();

  return 0;
}