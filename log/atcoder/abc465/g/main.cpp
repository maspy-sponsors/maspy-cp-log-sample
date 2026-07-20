#include "my_template.hpp"
#include "other/io.hpp"
#include "ds/fastset.hpp"
#include "mod/mod_inv.hpp"

/*
問題となるのは，mex != 0 となるような k だけ

k を固定したときにクエリできますか

結局，何かが 0 になったときの mex
*/

void solve() {
  LL(N, M, C, K);
  VEC(ll, A, N);

  LL(Q);
  VEC(pi, query, Q);
  for (auto &[i, x] : query) --i;

  vi X = A;
  for (auto &[i, x] : query) X.eb(x);

  {
    vi Y;
    for (auto &x : X) {
      Y.eb(x);
      Y.eb((x + 1) % M);
    }
    swap(X, Y);
    UNIQUE(X);
  }

  ll n = len(X);
  FastSet FS0(3 * n);
  FastSet FS1(3 * n);
  vi F(n);
  for (auto &x : A) {
    int k = LB(X, x);
    F[k]++;
  }

  FOR(i, n) {
    if (F[i] == 0) FS0.insert(i), FS0.insert(n + i), FS0.insert(n + n + i);
    if (F[i] == 1) FS1.insert(i), FS1.insert(n + i), FS1.insert(n + n + i);
  }

  // X[i] が 0 になるということが起こる回数
  ll g = gcd(C, M);
  ll c = C / g, m = M / g;
  ll ic = mod_inv(c, m);
  vc<u64> cnt(n);

  FOR(i, n) {
    ll a = X[i];
    if (a % g != 0) continue;
    ll t = (-a / g) * ic % m;
    if (t < 0) t += m;
    if (K <= t) continue;
    // t + xm <= K-1
    ll x = (K - 1 - t) / m;
    cnt[i] = x + 1;
    SHOW(t, cnt[i]);
  }

  FOR(i, 2 * n) X.eb(X[i] + M);
  FOR(i, 2 * n) cnt.eb(cnt[i]);

  auto calc = [&](int i) -> u64 {
    int j = FS0.next(i);
    if (j == 3 * n) return M;  // wow mex==M
    return X[j] - X[i];
  };

  u64 ANS = 0;
  FOR(i, n) { ANS += calc(i) * cnt[i]; }
  SHOW(ANS);

  vc<u64> CC(3 * n + 1);
  vc<u64> CX(3 * n + 1);
  FOR(i, 3 * n) CC[i + 1] = CC[i] + cnt[i];
  FOR(i, 3 * n) CX[i + 1] = CX[i] + (cnt[i] * X[i]);

  auto add = [&](int i) -> void {
    SHOW(F, i);
    F[i]++;
    if (F[i] >= 2) return;
    FS1.insert(i), FS1.insert(i + n), FS1.insert(i + n + n);
    FS0.erase(i), FS0.erase(i + n), FS0.erase(i + n + n);

    i += n;
    // i から見て何等かの計算を行うようになる
    int j = FS0.next(i);
    SHOW(i, j, X);
    if (j < 3 * n) {
      ANS += cnt[i] * u64(X[j] - X[i]);
    } else {
      ANS += cnt[i] * u64(M);
    }

    // いままで i を参照していたところの値が変更
    int k = FS0.prev(i);
    if (k == -1) k = i - n;
    SHOW(k, i, j);
    // FOR(p, k + 1, i) {
    //   ANS -= cnt[p] * (X[i] - X[p]);
    //   if (j == 3 * n) {
    //     ANS += cnt[p] * M;
    //   } else {
    //     ANS += cnt[p] * (X[j] - X[p]);
    //   }
    // }
    ANS -= (CC[i] - CC[k + 1]) * X[i];
    ANS += (CX[i] - CX[k + 1]);
    if (j == 3 * n) {
      ANS += (CC[i] - CC[k + 1]) * M;
    } else {
      ANS += (CC[i] - CC[k + 1]) * X[j];
      ANS -= (CX[i] - CX[k + 1]);
    }
  };

  auto rm = [&](int i) -> void {
    SHOW(F, i);
    F[i]--;
    if (F[i] > 0) return;

    i += n;
    // i から見て何等かの計算を行うようになる
    int j = FS0.next(i);
    SHOW(i, j);
    if (j < 3 * n) {
      ANS -= cnt[i] * (X[j] - X[i]);
    } else {
      ANS -= cnt[i] * M;
    }

    // いままで i を参照していたところの値が変更
    int k = FS0.prev(i);
    if (k == -1) k = i - n;
    SHOW(k, i, j);
    // FOR(p, k + 1, i) {
    //   ANS += cnt[p] * (X[i] - X[p]);
    //   if (j == 3 * n) {
    //     ANS -= cnt[p] * M;
    //   } else {
    //     ANS -= cnt[p] * (X[j] - X[p]);
    //   }
    // }
    ANS += (CC[i] - CC[k + 1]) * X[i];
    ANS -= (CX[i] - CX[k + 1]);
    if (j == 3 * n) {
      ANS -= (CC[i] - CC[k + 1]) * M;
    } else {
      ANS -= (CC[i] - CC[k + 1]) * X[j];
      ANS += (CX[i] - CX[k + 1]);
    }

    i -= n;
    FS1.erase(i), FS1.erase(i + n), FS1.erase(i + n + n);
    FS0.insert(i), FS0.insert(i + n), FS0.insert(i + n + n);
  };

  auto solve = [&](int x, int y) -> void {
    int s = LB(X, x);
    int t = LB(X, y);

    SHOW(s, t);
    // s が消えて t が入ります
    add(t), rm(s);
    SHOW(X, cnt, F, ANS);
    print(ANS);
    // add(s), rm(t);
  };

  FOR(q, Q) {
    auto [i, x] = query[q];
    solve(A[i], x);
    A[i] = x;
  }
}

signed main() {
  int T = 1;
  // INT(T);
  FOR(T) solve();
  return 0;
}
