#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "poly/convolution.hpp"

using mint = modint998;

/*
行列をかけて N 次係数をとるという形になるのではないか？
*/

using poly = vc<mint>;
using MAT = array<array<poly, 3>, 3>;

void add(poly &f, poly g) {
  if (len(f) < len(g)) f.resize(len(g));
  FOR(i, len(g)) f[i] += g[i];
}

MAT mul(MAT &A, MAT &B) {
  MAT ANS{};
  FOR(a, 3) FOR(b, 3) FOR(c, 3) {
    add(ANS[a][c], convolution<mint>(A[a][b], B[b][c]));
  }
  return ANS;
}

/*
B のときに区間の個数とマッチングの選び方をかけざん

クエリ
[x^N](base^n)[0][0]


ダメです！完全に一致する区間が 2 個あるととてもだるい！！
AA のときにラベルをつけておけばよい？
*/

void solve() {
  LL(N, U);
  MAT base;
  {
    // .
    add(base[0][0], {1});
    add(base[1][1], {1});
    add(base[2][2], {1});
    // A
    add(base[0][1], {1});
    add(base[1][2], {1});
    // AA
    add(base[0][2], {inv<mint>(2)});

    // B
    add(base[1][0], {0, 1});
    add(base[2][1], {0, 2});
    // BA
    add(base[1][1], {0, 1});
    add(base[2][2], {0, 2});
    // BAA
    add(base[1][2], {0, inv<mint>(2)});

    // BB
    add(base[2][0], {0, 0, 1});
    // BBA
    add(base[2][1], {0, 0, 1});
    // BBAA
    add(base[2][2], {0, 0, inv<mint>(2)});
  }

  MAT A{};
  FOR(i, 3) add(A[i][i], {1});

  // {
  //   MAT A{};
  //   FOR(i, 3) add(A[i][i], {1});
  //   FOR(U + 1) {
  //     A = mul(A, base);
  //     poly f = A[0][0];
  //     mint ANS = (N < len(f) ? f[N] : 0);
  //     ANS *= fact<mint>(N);
  //     print(ANS);
  //   }
  //   return;
  // }

  vc<mint> ANS(U + 2);

  auto dfs = [&](auto &dfs, MAT A, int L, int R, int deg) -> MAT {
    /*
    [x^deg] A * base^{i-L}
    return : base^{R-L}
    低次の項がいらないというのがあるはずで
    */
    int cut = deg - 2 * (R - L);
    if (0 < cut) {
      // [0,cut) を削る
      FOR(i, 3) FOR(j, 3) {
        poly &f = A[i][j];
        if (len(f) < cut) f.resize(cut);
        f = {f.begin() + cut, f.end()};
      }
      deg -= cut;
    }
    FOR(i, 3) FOR(j, 3) { A[i][j].resize(deg + 1); }
    if (R == L + 1) {
      ANS[L] = A[0][0][deg];
      return base;
    }
    int M = (L + R) / 2;
    auto B = dfs(dfs, A, L, M, deg);
    auto C = dfs(dfs, mul(A, B), M, R, deg);
    return mul(B, C);
  };
  dfs(dfs, A, 0, U + 2, N);

  FOR(n, 2, U + 2) {
    SHOW(N, n, ANS[n]);
    print(ANS[n] * fact<mint>(N));
  }
}

int main() {
  // test();
  // return 0;
  // INT(T);
  // FOR(T)
  solve();
}