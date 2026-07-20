#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, Q);
  STR(S);
  vc<int> A = s_to_vi(S, '0');

  vc<int> X(N), Y(N), XX(N - 1), YY(N - 1);
  FOR(i, N) X[i] += (A[i] == 0);
  FOR(i, N) Y[i] += (A[i] == 1);

  FOR(i, N - 1) XX[i] = (A[i] == A[i + 1] && A[i] == 0);
  FOR(i, N - 1) YY[i] = (A[i] == A[i + 1] && A[i] == 1);

  X = cumsum<int>(X);
  Y = cumsum<int>(Y);
  XX = cumsum<int>(XX);
  YY = cumsum<int>(YY);

  auto f = [&](ll L, ll R) -> void {
    ll x = X[R] - X[L];
    ll y = Y[R] - Y[L];
    ll xx = XX[R - 1] - XX[L];
    ll yy = YY[R - 1] - YY[L];

    if (xx > 0 && yy > 0) return print(xx + yy - 2);
    if (xx == 0 && yy == 0) return print(0);

    if (xx > 0) {
      if (A[L] == 1 || A[R - 1] == 1) return print(xx - 1);
      return print(xx);
    }
    if (yy > 0) {
      if (A[L] == 0 || A[R - 1] == 0) return print(yy - 1);
      return print(yy);
    }
  };

  FOR(Q) {
    LL(L, R);
    --L;
    f(L, R);
  }
}

signed main() {
  solve();
  return 0;
}