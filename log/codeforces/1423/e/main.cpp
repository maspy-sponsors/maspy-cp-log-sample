#include "my_template.hpp"
#include "other/io.hpp"
#include "geo/base.hpp"
#include "random/base.hpp"
#include "geo/distance.hpp"

using Re = double;

void solve() {
  Re H, W;
  read(H, W);
  LL(N);
  using P = Point<Re>;
  vvc<P> dat;
  Re theta = RNG(0, 1e9) / Re(1e9);
  FOR(N) {
    LL(n);
    VEC(P, A, n);
    for (auto &p : A) p = p.rotate(theta);
    A.eb(A[0]);
    dat.eb(A);
  }

  vc<Re> AREA(N);
  FOR(i, N) {
    FOR(j, len(dat[i]) - 1) {
      P a = dat[i][j], b = dat[i][j + 1];
      AREA[i] += a.det(b);
    }
    if (AREA[i] < 0) {
      reverse(all(dat[i]));
      AREA[i] = -AREA[i];
    }
  }

  Re eps = 1e-8;

  auto check = [&](int i, P p, Re r) -> bool {
    int n = len(dat[i]) - 1;
    // side
    int cnt = 0;
    FOR(j, n) {
      P A = dat[i][j], B = dat[i][j + 1];
      if (A.y > B.y) swap(A, B);
      Segment<Re> S(A, B);
      Re d = distance<Re, Re, Re>(S, p);
      if (d <= r + eps) return 1;
      if (A.y <= p.y && p.y <= B.y) {
        Re det = (A - p).det(B - p);
        cnt += (det > 0);
      }
    }
    return (cnt % 2 == 1);
  };

  LL(Q);
  FOR(Q) {
    P p;
    Re r;
    read(p, r);
    p = p.rotate(theta);
    vc<int> I;
    FOR(i, N) if (check(i, p, r)) I.eb(i);
    Re ans = 0;
    for (auto &i : I) ans += AREA[i];
    ans *= 0.5;
    print(ans, len(I), I);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}