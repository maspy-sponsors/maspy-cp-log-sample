#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N, M);
  VEC(ll, A, N);
  VEC(ll, B, N - 1);

  vi X(N);
  FOR(i, 1, N) {
    ll now = A[i] + A[i - 1] + X[i - 1];
    ll need = B[i - 1] - now;
    X[i] = bmod(need, M);
  }

  A.clear(), B.clear();
  FOR(i, N) { (i % 2 == 0 ? A : B).eb(X[i]); }

  // A + B -

  sort(all(A));
  sort(all(B));
  auto Ac = cumsum<ll>(A);
  auto Bc = cumsum<ll>(B);

  auto f = [&](ll x) -> ll {
    // A += x
    // B -= x
    ll ANS = 0;
    ll k = LB(A, M - x);
    ANS += Ac[len(A)] + x * len(A);
    ANS -= (len(A) - k) * M;
    k = LB(B, x);
    ANS += Bc[len(B)] - x * len(B);
    ANS += k * M;
    return ANS;
  };

  ll ANS = f(0);
  for (auto &x : A) chmin(ANS, f(M - x));
  for (auto &x : B) chmin(ANS, f(x));
  print(ANS);
}

signed main() {
  solve();
  return 0;
}