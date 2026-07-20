#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/base.hpp"
#include "random/base.hpp"

using P = Point<ll>;

void solve() {
  LL(N, R);
  VEC(P, A, N);

  ll H = 0;
  while (H * H <= 3 * R * R) ++H;
  SHOW(R, H);
  /*
  2iR,2jH
  (2i+1)R,(2j+1)H
  */
  while (1) {
    ll dx = RNG(0, 2 * R);
    ll dy = RNG(0, 2 * H);

    vc<P> ANS;
    ll OK = 0;
    FOR(i, N) {
      ll a = floor<ll>(A[i].x, R);
      ll b = floor<ll>(A[i].y, H);
      ll ok = 0;
      FOR(da, -3, 4) FOR(db, -3, 4) {
        if ((a + da + b + db) % 2 != 0) continue;
        ll x = (a + da) * R + dx;
        ll y = (b + db) * H + dy;
        P p = A[i] - P(x, y);
        if (p.dot(p) <= R * R) {
          ANS.eb(P(x, y));
          ok = 1;
        }
        // assert(ok <= 1);
      }
      OK += ok;
    }
    UNIQUE(ANS);
    if (OK * 100 >= 89 * N) {
      // ok
      print(len(ANS));
      for (auto &p : ANS) print(p.x, p.y);
      // for (auto& p : ANS) {
      //   for (auto& q : ANS) {
      //     ll d = (p - q).dot(p - q);
      //     assert(d == 0 || d >= 4 * R * R);
      //   }
      // }
      return;
    }
  }
}

signed main() {
  // INT(T);
  // FOR(T)
  solve();
}