#include "my_template.hpp"
#include "other/io.hpp"

void test() {
  FOR(d, 1, 500) FOR(c, 1, d) FOR(b, 1, c) FOR(a, 1, b) {
    ll X = a + b + c + d;
    ll k = 0;
    k += (X % (a + b) == 0);
    k += (X % (a + c) == 0);
    k += (X % (a + d) == 0);
    k += (X % (b + c) == 0);
    k += (X % (b + d) == 0);
    k += (X % (c + d) == 0);

    ll g = gcd(gcd(gcd(a, b), c), d);
    if (g == 1 && k == 4) {
      SHOW(a, b, c, d);
    }
  }
}

/*
a = 1 b = 5 c = 7 d = 11
a = 1 b = 11 c = 19 d = 29
これだけという説
*/

void solve() {
  LL(N, Q);

  ll ANS = 0;

  set<ll> S;
  vvc<ll> dat;
  dat.eb(vi{1, 5, 7, 11});
  dat.eb(vi{1, 11, 19, 29});

  auto add = [&](ll x) -> void {
    FOR(tp, 2) {
      vi &A = dat[tp];
      FOR(i, 4) {
        if (x % A[i] != 0) continue;
        ll ok = 0;
        ok += S.count(x / A[i] * A[0]);
        ok += S.count(x / A[i] * A[1]);
        ok += S.count(x / A[i] * A[2]);
        ok += S.count(x / A[i] * A[3]);
        if (ok == 3) ANS += 1;
      }
    }
    S.emplace(x);
  };

  auto rm = [&](ll x) -> void {
    S.erase(x);
    FOR(tp, 2) {
      vi &A = dat[tp];
      FOR(i, 4) {
        if (x % A[i] != 0) continue;
        ll ok = 0;
        ok += S.count(x / A[i] * A[0]);
        ok += S.count(x / A[i] * A[1]);
        ok += S.count(x / A[i] * A[2]);
        ok += S.count(x / A[i] * A[3]);
        if (ok == 3) ANS -= 1;
      }
    }
  };

  FOR(N) {
    LL(x);
    add(x);
  }

  FOR(Q) {
    INT(t, x);
    if (t == 1) add(x);
    if (t == 2) rm(x);
    print(ANS);
  }
}

signed main() {
  // test();
  // return 0;
  solve();
}
