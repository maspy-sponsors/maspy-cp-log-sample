#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(N);
  STR(S);
  vc<int> A(N), B(N);
  FOR(i, N) A[i] += (S[i] == 'A');
  FOR(i, N) A[i] -= (S[i] == 'T');
  FOR(i, N) B[i] += (S[i] == 'C');
  FOR(i, N) B[i] -= (S[i] == 'G');

  A = cumsum<int>(A);
  B = cumsum<int>(B);

  ll ANS = 0;
  FOR(R, N + 1) FOR(L, R) {
    if (A[L] == A[R] && B[L] == B[R]) ++ANS;
  }
  print(ANS);
}

int main() { solve(); }