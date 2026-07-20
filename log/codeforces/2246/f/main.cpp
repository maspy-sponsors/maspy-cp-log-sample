#include "my_template.hpp"
#include "other/io.hpp"
#include "seq/inversion.hpp"
#include "random/base.hpp"

pair<bool, vc<int>> trial(vc<int> A) {
  int N = len(A);
  vc<int> pos(N);
  FOR(i, N) pos[A[i]] = i;
  vc<int> ANS;

  auto check = [&]() -> bool {
    if (len(ANS) > 4 * N) return 0;
    FOR(i, N) if (A[i] != i) return 0;
    return 1;
  };

  if (check()) return {true, ANS};

  vc<int> B(N);
  auto op = [&](int i) -> void {
    assert(0 <= i && i < N - 1);
    B[0] = A[i];
    FOR(j, 1, i + 1) B[j] = A[j - 1];
    FOR(j, i + 1, N - 1) B[j] = A[j + 1];
    B[N - 1] = A[i + 1];

    ANS.eb(i);
    swap(A, B);
    FOR(i, N) pos[A[i]] = i;
  };

  int K = RNG(0, N + 1);
  FOR(K) {
    int i = RNG(0, N - 1);
    op(i);
  }

  if (pos[N - 2] == N - 1) op(0);
  assert(pos[N - 2] != N - 1);
  if (pos[N - 2] != 0) {
    op(pos[N - 2]);
  }
  int p = N - 2;
  // prefix [p,N-1)
  while (p > 1) {
    // SHOW(A, p);
    FOR(k, p, N - 1) assert(A[k - p] == k);
    if (pos[p - 1] < N - 1) {
      op(pos[p - 1]);
      --p;
      continue;
    }
    op(N - 3);
    // SHOW(A);
    op(N - 2);
    // SHOW(A);
    op(0);
    // SHOW(A);
    // SHOW(A, p);
    --p;
  }
  op(N - 2);
  SHOW(p, A);
  FOR(3) {
    if (check()) {
      return {true, ANS};
    }
    op(N - 2), op(0);
  }
  return {false, ANS};
}

void solve() {
  LL(N);
  VEC(int, A, N);
  for (auto &x : A) --x;

  ll k = inversion(A);
  if (k % 2 == 1 && N % 2 == 0) return print(-1);
  while (1) {
    auto [ok, ANS] = trial(A);
    if (!ok) continue;
    for (auto &x : ANS) ++x;
    print(len(ANS));
    print(ANS);
    return;
  }
}

signed main() {
  INT(T);
  FOR(T) solve();
  return 0;
}