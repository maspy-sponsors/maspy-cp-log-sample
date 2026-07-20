#include "my_template.hpp"
#include "other/io.hpp"

ll A[12][12][12][12][12][12];

void solve() {
  LL(N);
  FOR(N) {
    STR(S);
    LL(v);
    vc<int> B = s_to_vi(S, '0');
    for (auto& x : B) ++x;
    A[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]] += v;
  }

  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a + 1][b][c][d][e][f] += A[a][b][c][d][e][f];
  }
  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a][b + 1][c][d][e][f] += A[a][b][c][d][e][f];
  }
  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a][b][c + 1][d][e][f] += A[a][b][c][d][e][f];
  }
  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a][b][c][d + 1][e][f] += A[a][b][c][d][e][f];
  }
  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a][b][c][d][e + 1][f] += A[a][b][c][d][e][f];
  }
  FOR(a, 11) FOR(b, 11) FOR(c, 11) FOR(d, 11) FOR(e, 11) FOR(f, 11) {
    A[a][b][c][d][e][f + 1] += A[a][b][c][d][e][f];
  }

  LL(Q);
  FOR(Q) {
    STR(S, T);
    vc<int> X = s_to_vi(S, '0');
    vc<int> Y = s_to_vi(T, '0');
    for (auto& x : Y) ++x;

    bool ng = 0;
    FOR(i, 6) if (X[i] >= Y[i]) { ng = 1; }
    if (ng) {
      print(0);
      continue;
    }

    ll ANS = 0;
    FOR(s, 1 << 6) {
      vc<int> B(6);
      FOR(i, 6) B[i] = (has_kth_bit(s, i) ? Y[i] : X[i]);
      ll x = A[B[0]][B[1]][B[2]][B[3]][B[4]][B[5]];
      // SHOW(s, x);
      ANS += popcnt_sgn(s) * x;
    }
    print(ANS);
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}