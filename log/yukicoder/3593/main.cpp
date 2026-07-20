#include "my_template.hpp"
#include "other/io.hpp"

#include "ds/unionfind/unionfind.hpp"
#include "random/shuffle.hpp"
#include "linalg/matrix_mul.hpp"

using ARR = array<int, 9>;
using MAT = array<array<int, 9>, 9>;

void shuffle(ARR& A) {
  FOR(i, 9) {
    int j = RNG(0, i + 1);
    if (i != j) swap(A[i], A[j]);
  }
}

MAT gen_C(MAT A, MAT B) {
  int N = 9;
  MAT C = matrix_mul<int, 9>(A, B);
  FOR(i, N) FOR(j, N) C[i][j] %= 9;
  return C;
}

bool check(MAT X) {
  int N = 9;
  int FULL = 511;
  // FOR(i, N) {
  //   int s = 0;
  //   FOR(j, N) s |= 1 << X[i][j];
  //   assert(s == FULL);
  //   if (s != FULL) return 0;
  // }
  // FOR(i, N) {
  //   int s = 0;
  //   FOR(j, N) s |= 1 << X[j][i];
  //   assert(s == FULL);
  //   if (s != FULL) return 0;
  // }
  FOR(i, 3) FOR(j, 3) {
    int s = 0;
    FOR(a, 3) FOR(b, 3) s |= 1 << X[3 * i + a][3 * j + b];
    if (s != FULL) return 0;
  }
  return 1;
}

void solve() {
  int N = 9;

  ARR X, Y;
  FOR(i, N) X[i] = Y[i] = i;
  while (1) {
    shuffle(X);
    shuffle(Y);
    ARR Z{};
    FOR(a, 3) FOR(b, 3) {
      FOR(c, 3) FOR(d, 3) {
        int e = (a + c) % 3, f = (b + d) % 3;
        Z[3 * e + f] += X[3 * a + b] * Y[3 * c + d];
      }
    }
    FOR(i, 9) Z[i] %= 9;
    int s = 0;
    for (auto& z : Z) s |= 1 << z;
    if (s == 511) break;
  }

  MAT A, B;
  FOR(a, 3) FOR(b, 3) {
    FOR(c, 3) FOR(d, 3) {
      // (a,b) が表す置換
      int u = 3 * c + d;
      int e = (a + c) % 3, f = (b + d) % 3;
      int v = 3 * e + f;
      A[u][v] = X[3 * a + b];
      B[u][v] = Y[3 * a + b];
    }
  }

  MAT C = gen_C(A, B);
  ARR P, Q, R;
  MAT A0 = A, B0 = B;
  FOR(i, N) P[i] = Q[i] = R[i] = i;
  while (1) {
    shuffle(P);
    shuffle(Q);
    shuffle(R);
    MAT A{}, B{};
    FOR(i, N) FOR(j, N) A[P[i]][Q[j]] = A0[i][j];
    FOR(i, N) FOR(j, N) B[Q[i]][R[j]] = B0[i][j];
    if (!check(A)) continue;
    if (!check(B)) continue;
    MAT C = gen_C(A, B);
    if (check(C)) {
      FOR(i, N) print(A[i]);
      FOR(i, N) print(B[i]);
      break;
    }
  }
}

signed main() {
  solve();
  return 0;
}