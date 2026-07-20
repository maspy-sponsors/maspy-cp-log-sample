#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  vc<int> A(N), B(N);
  FOR(i, N) read(A[i], B[i]);

  for (auto& x : A)
    if (x != -1) --x;
  for (auto& x : B)
    if (x != -1) --x;

  vc<int> X;
  for (auto& x : A)
    if (x != -1) X.eb(x);
  for (auto& x : B)
    if (x != -1) X.eb(x);
  sort(all(X));
  FOR(i, len(X) - 1) if (X[i] == X[i + 1]) return No();
  FOR(i, N) if (A[i] != -1 && B[i] != -1 && A[i] > B[i]) return No();

  vc<int> dp(N + N + 1);
  dp[0] = 1;

  auto can = [&](int L, int R) -> bool {
    if ((R - L) % 2 == 1) return 0;
    int n = (R - L) / 2;

    FOR(i, n) {
      int s = L + i, t = s + n;
      int k = 0;
      FOR(j, N) {
        int a = A[j], b = B[j];
        if (a == s || b == t) {
          ++k;
          if (b != -1 && b != t) return false;
          if (a != -1 && a != s) return false;
        }
      }
      if (k == 2) return false;
    }
    return true;
  };

  FOR(L, N + N + 1) {
    FOR(R, L, N + N + 1) {
      if (dp[L] && can(L, R)) dp[R] = 1;
    }
  }
  Yes(dp[N + N]);
}

int main() { solve(); }