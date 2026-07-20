#include "my_template.hpp"
#include "other/io.hpp"

ll F(vi A) {
  ll N = len(A);
  vc<int> B(N + 1);
  int me = 0;
  ll ans = 0;
  for (auto &a : A) {
    B[a] = 1;
    while (B[me]) ++me;
    ans ^= me;
  }
  return ans;
}

void test(int N) {
  vi A(N);
  FOR(i, N) A[i] = i;
  map<int, vi> MP;
  do {
    int ans = F(A);
    if (MP.count(ans)) continue;
    MP[ans] = A;
  } while (next_permutation(all(A)));

  for (auto &[X, A] : MP) SHOW(N, X, A);
}

/*
N 以上
1+2+...+N 以下
全部
0000367
1245036
*/

vi solve(ll N, ll K) {
  ll L = 0, R = infty<ll>;
  if ((N & (N - 1)) == 0) {
    L = N;
    R = N + N - 1;
  } else {
    ll k = topbit(N);
    L = 0;
    R = (2 << k) - 1;
  }

  if (!(L <= K && K <= R)) return {};

  if (N == 1) {
    return {0};
  }
  if (N == 2) {
    if (K == 2) return {1, 0};
    return {0, 1};
  }

  if (((N & (N - 1)) == 0) && K == N) {
    vi A(N);
    FOR(i, N) A[i] = i;
    return A;
  }

  vi B(N);
  ll X = [&]() -> ll {
    FOR(X, N) {
      ll Y = (K ^ N ^ X);
      // ... Y,X,N
      if (Y <= N - 2 && X <= N - 1 && Y <= X && X < N) return X;
    }
    return -1;
  }();
  assert(X != -1);
  B[N - 1] = N;
  B[N - 2] = X;
  ll Y = K ^ N ^ X;
  B[N - 3] = Y;

  int n = 0;
  FOR(i, N) n += (B[i] == 0);

  if (n == N - 1) {
    vi A;
    FOR(i, 1, N) A.eb(i);
    A.eb(0);
    return A;
  }
  int a = B[n];
  int x = 0;
  vi A;
  FOR(i, n) {
    while (x == 0 || x == X || x == Y) ++x;
    A.eb(x);
    ++x;
  }
  A.eb(0);
  if (0 < Y) A.eb(Y);
  if (Y < X) A.eb(X);
  while (len(A) < N) {
    while (x == 0 || x == X || x == Y) ++x;
    A.eb(x);
    ++x;
  }
  SHOW(N, K, B, A);
  return A;
}

void test() {
  FOR(N, 1, 50) {
    FOR(K, 200) {
      SHOW(N, K);
      vi A = solve(N, K);
      if (A.empty()) continue;
      {
        vi B = A;
        sort(all(B));
        FOR(i, N) assert(B[i] == i);
      }
      ll ans = F(A);
      SHOW(N, K, A, ans);
      assert(K == ans);
    }
  }
  print("OK");
}

void solve() {
  LL(N, K);
  vi A = solve(N, K);
  if (A.empty()) return NO();
  YES();
  print(A);
}

signed main() {
  // test();
  // // solve(7, 16);
  // // return 0;
  // // FOR(N, 1, 11) test(N);
  // return 0;
  INT(T);
  FOR(T) solve();
}