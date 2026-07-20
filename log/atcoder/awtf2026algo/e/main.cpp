#include "my_template.hpp"
#include "other/io.hpp"

#include "mod/modint.hpp"
#include "ds/segtree/segtree.hpp"
#include "seq/cartesian_tree.hpp"

using mint = modint998;

mint solve_fixed_parity_EVEN(ll N, ll M, vi A) {
  vc<int> odd_cnt(N + 1);
  FOR(i, N) odd_cnt[i + 1] = odd_cnt[i] + (popcnt(A[i]) % 2);

  vi cut(N + 1);
  FOR(i, N + 1) cut[i] = (odd_cnt[i] % 2 == 0);
  vi cut_c = cumsum<ll>(cut);

  vc<int> I;
  FOR(i, N) if (popcnt(A[i]) % 2 == 1) I.eb(i);
  mint ANS = 0;
  FOR(k, len(I) / 2) {
    ll s = I[2 * k], t = I[2 * k + 1];
    ll bad = 1;
    if (A[s] != A[t]) {
      bad = 0;
    } else {
      FOR(i, s + 1, t) {
        if (popcnt(A[s] ^ A[i]) != 1) bad = 0;
      }
    }
    ll cost = (t - s) + bad;
    // 0<=L<=s
    ll c1 = cut_c[s + 1];
    // t+1<=R<=N
    ll c2 = cut_c[N + 1] - cut_c[t + 1];
    SHOW(A, s, t, cost, c1, c2);
    ANS += mint(cost) * c1 * c2;
  }
  return ANS;
}

array<mint, 4> single(ll N, ll M, vi A) {
  array<mint, 4> ANS{};
  vc<int> I;
  FOR(i, N) if (popcnt(A[i]) % 2 == 1) I.eb(i);
  assert(len(I) % 2 == 0);
  if (I.empty()) return {};

  FOR(i, len(I) / 2) ANS[0] += I[2 * i + 1] - I[2 * i];

  struct Obj {
    int kind, l, r;
    Obj(int k, int l, int r) : kind(k), l(l), r(r) {}
  };

  vc<Obj> obj;

  vc<pair<int, int>> bad_range;

  FOR(k, len(I) + 1) {
    if (k % 2 == 0) {
      int s = (k == 0 ? -1 : I[k - 1]);
      int t = (k == len(I) ? N : I[k]);
      FOR(i, s + 1, t) {
        int k = (M - popcnt(A[i])) / 2;
        FOR(k) { obj.eb(Obj(1, i, i)); }
      }
    } else {
      int s = I[k - 1], t = I[k];
      bool exist = 0;
      FOR(i, s, t + 1) if (popcnt(A[i]) < M - 1) exist = 1;
      if (!exist) {
        obj.eb(Obj(0, s, t));
      } else {
        bool bad = (A[s] == A[t]);
        FOR(i, s + 1, t) bad = bad && (popcnt(A[s] ^ A[i]) == 1);

        obj.eb(Obj(0, s, s));

        int l = len(obj);
        int prv = s;
        FOR(i, s, t + 1) {
          int m = (M - popcnt(A[i])) / 2;
          FOR(m) {
            obj.eb(Obj(1, prv, i));
            prv = i;
          }
        }
        obj.eb(Obj(1, prv, t));
        int r = len(obj);

        ++l, --r;

        obj.eb(Obj(0, t, t));
        if (bad) bad_range.eb(l, r);
      }
    }
  }

  int n = len(obj);
  vvc<int> ids(2 * n + 1);
  vc<int> lv(n);
  {
    int now = n;
    FOR(i, n) {
      Obj x = obj[i];
      if (x.kind == 0) {
        now -= 1;
        lv[i] = now, ids[now].eb(i);
      } else {
        lv[i] = now, ids[now].eb(i);
        now += 1;
      }
    }
  }

  vc<int> can_del(n);
  vc<int> nxt_del(n, -1);
  vc<int> prv_del(n, -1);

  FOR(lv, 2 * n + 1) {
    vc<int> &I = ids[lv];
    if (I.empty()) continue;
    int ks = obj[I[0]].kind;
    int kt = obj[I.back()].kind;
    if (ks == 0 && kt == 0) {
      // invalid
      return {};
    }
    if (ks != kt) {
      // unremovable
      FOR(i, len(I) / 2) {
        int dx = obj[I[2 * i + 1]].l - obj[I[2 * i + 0]].r;
        ANS[1] += dx;
      }
    }
    if (ks == 1 && kt == 1) {
      int m = len(I) / 2;
      // prefix k-match, suffix k-match
      vc<ll> pre(m + 1), suf(m + 1);
      FOR(i, m) {
        int a = I[2 * i + 0], b = I[2 * i + 1];
        int dx = obj[b].l - obj[a].r;
        pre[i + 1] = pre[i] + dx;
      }
      FOR(i, m) {
        int a = I[2 * m - 2 * i - 1], b = I[2 * m - 2 * i];
        int dx = obj[b].l - obj[a].r;
        suf[i + 1] = suf[i] + dx;
      }

      ll best = infty<ll>;
      FOR(i, m + 1) chmin(best, pre[i] + suf[m - i]);
      ANS[2] += best;

      vc<int> del;
      FOR(i, m + 1) {
        int k = I[2 * i];
        if (pre[i] + suf[m - i] == best) del.eb(k);
      }
      FOR(i, len(del)) {
        int b = del[i];
        int a = (i == 0 ? -1 : del[i - 1]);
        int c = (i + 1 == len(del) ? -1 : del[i + 1]);
        can_del[b] = 1;
        prv_del[b] = a, nxt_del[b] = c;
      }
    }
  }

  SHOW(can_del, nxt_del, prv_del);

  // さらに内部がすべて削除可能であるもの
  {
    vc<pair<int, int>> tmp;
    for (auto &[l, r] : bad_range) {
      bool ok = 1;
      FOR(i, l, r) ok = ok && (can_del[i]);
      if (ok) tmp.eb(l, r);
    }
    swap(bad_range, tmp);
  }

  SHOW(bad_range);
  //
  int p = 0;
  while (p < len(bad_range)) {
    int q = p;
    while (q + 1 < len(bad_range) &&
           nxt_del[bad_range[q].se - 1] == bad_range[q + 1].fi) {
      ++q;
    }
    if (prv_del[bad_range[p].fi] == -1 && nxt_del[bad_range[q].se - 1] == -1) {
      ANS[3] += 1;
    }
    p = q + 1;
  }
  return ANS;
}

struct Mono0 {
  using value_type = tuple<mint, mint, mint>;
  using X = value_type;
  static X op(X L, X R) {
    auto [ans1, a1, b1] = L;
    auto [ans2, a2, b2] = R;
    mint ans = ans1 + ans2 + a1 * b2;
    return {ans, a1 + a2, b1 + b2};
  }
  static constexpr X unit() { return {0, 0, 0}; }
  static constexpr bool commute = 0;
};

array<mint, 4> many(ll N, ll M, vi A) {
  array<mint, 4> ANS{};
  vc<int> I;
  FOR(i, N) if (popcnt(A[i]) % 2 == 1) I.eb(i);
  assert(len(I) % 2 == 0);
  if (I.empty()) return {};

  struct Obj {
    int kind, l, r;
    Obj(int k, int l, int r) : kind(k), l(l), r(r) {}
  };

  vc<Obj> obj;

  vc<pair<int, int>> bad_range;

  FOR(k, len(I) + 1) {
    if (k % 2 == 0) {
      int s = (k == 0 ? -1 : I[k - 1]);
      int t = (k == len(I) ? N : I[k]);
      FOR(i, s + 1, t) {
        int k = (M - popcnt(A[i])) / 2;
        FOR(k) { obj.eb(Obj(1, i, i)); }
      }
    } else {
      int s = I[k - 1], t = I[k];
      bool exist = 0;
      FOR(i, s, t + 1) if (popcnt(A[i]) < M - 1) exist = 1;
      if (!exist) {
        obj.eb(Obj(0, s, t));
      } else {
        bool bad = (A[s] == A[t]);
        FOR(i, s + 1, t) bad = bad && (popcnt(A[s] ^ A[i]) == 1);

        obj.eb(Obj(0, s, s));

        int l = len(obj);
        int prv = s;
        FOR(i, s, t + 1) {
          int m = (M - popcnt(A[i])) / 2;
          FOR(m) {
            obj.eb(Obj(1, prv, i));
            prv = i;
          }
        }
        obj.eb(Obj(1, prv, t));
        int r = len(obj);

        ++l, --r;

        obj.eb(Obj(0, t, t));
        if (bad) bad_range.eb(l, r);
      }
    }
  }

  int n = len(obj);
  vvc<int> ids(2 * n + 1);
  vc<int> lv(n);
  {
    int now = n;
    FOR(i, n) {
      Obj x = obj[i];
      if (x.kind == 0) {
        now -= 1;
        lv[i] = now, ids[now].eb(i);
      } else {
        lv[i] = now, ids[now].eb(i);
        now += 1;
      }
    }
  }

  vi parity(N + 1);
  FOR(i, N) parity[i + 1] = (parity[i] + popcnt(A[i])) & 1;

  vi H(N + 1);
  for (auto &X : obj) {
    int x = (X.kind == 0 ? -1 : 1);
    H[X.r + 1] += x;
  }
  FOR(i, N) H[i + 1] += H[i];
  for (auto &x : H) x += n;

  {
    // ANS[0]
    // FOR(i, len(I) / 2) {
    //   int a = I[2 * i + 0];
    //   int b = I[2 * i + 1];
    //   int dx = b - a;
    //   FOR(L, a + 1) FOR(R, b + 1, N + 1) {
    //     if (H[L] <= H[R] && parity[L] == 0 && parity[R] == 0) ANS[0] += dx;
    //   }
    // }

    vc<int> left(2 * n + 1), right(2 * n + 1);
    auto segf = [&](int i) -> tuple<mint, mint, mint> {
      mint ans = mint(left[i]) * right[i];
      return {ans, left[i], right[i]};
    };

    SegTree<Mono0> seg(2 * n + 1, segf);
    int aa = 0, bb = N + 1;
    mint now = 0;
    FOR(i, len(I) / 2) {
      int a = I[2 * i + 0];
      int b = I[2 * i + 1];
      while (aa < a + 1) {
        if (parity[aa] == 0) {
          left[H[aa]]++;
          seg.set(H[aa], segf(H[aa]));
        }
        ++aa;
      }
      while (b + 1 < bb) {
        --bb;
        if (parity[bb] == 0) {
          right[H[bb]]++;
          seg.set(H[bb], segf(H[bb]));
        }
      }
      while (b + 1 > bb) {
        if (parity[bb] == 0) {
          right[H[bb]]--;
          seg.set(H[bb], segf(H[bb]));
        }
        ++bb;
      }
      assert(a + 1 == aa && b + 1 == bb);
      int dx = b - a;
      // FOR(L, a + 1) FOR(R, b + 1, N + 1) {
      //   if (H[L] <= H[R] && parity[L] == 0 && parity[R] == 0) ANS[0] += dx;
      // }
      ANS[0] += mint(dx) * get<0>(seg.prod_all());
    }
  }

  {
    // ANS[1]
    vvc<pair<int, int>> dat1(N + 1), dat2(N + 1);
    FOR(lv, 2 * n + 1) {
      vc<int> &I = ids[lv];
      if (I.empty()) continue;
      // even
      int m = len(I);
      FOR(i, m - 1) {
        Obj P = obj[I[i]];
        Obj Q = obj[I[i + 1]];
        int dx = Q.l - P.r;
        if (dx == 0) continue;
        // int a = P.l, b = Q.r;
        int a = P.l, b = P.l;
        if (P.kind == 0) {
          // -, +
          // FOR(L, a + 1) FOR(R, b + 1, N + 1) {
          //   if (lv < H[L] && H[L] <= H[R] && parity[L] == 0 && parity[R] ==
          //   0) {
          //     ANS[1] += dx;
          //   }
          // }
          dat1[a].eb(lv, dx);
        } else {
          // +, -
          dat2[a].eb(lv, dx);
          // FOR(L, a + 1) FOR(R, b + 1, N + 1) {
          //   if (H[L] <= H[R] && H[R] <= lv && parity[L] == 0 &&
          //       parity[R] == 0) {
          //     ANS[1] += dx;
          //   }
          // }
        }
      }
    }

    {
      vc<int> left(2 * n + 1), right(2 * n + 1);
      FOR(i, N + 1) {
        if (parity[i] == 0) left[H[i]]++;
      }
      auto segf = [&](int i) -> tuple<mint, mint, mint> {
        return {mint(left[i]) * right[i], left[i], right[i]};
      };
      SegTree<Mono0> seg(2 * n + 1, segf);
      FOR_R(a, N + 1) {
        for (auto &[lv, dx] : dat1[a]) {
          ANS[1] += get<0>(seg.prod(lv + 1, 2 * n + 1)) * dx;
        }
        for (auto &[lv, dx] : dat2[a]) {
          ANS[1] += get<0>(seg.prod(0, lv + 1)) * dx;
        }
        if (parity[a] == 0) {
          left[H[a]]--, right[H[a]]++;
          seg.set(H[a], segf(H[a]));
        }
      }
    }
  }

  // +-+-+-+
  // FOR(lv, 2 * n + 1) {
  //   vc<int>& I = ids[lv];
  //   int m = len(I);
  //   if (m == 0) continue;

  //   vi pos;
  //   FOR(i, m) {
  //     if (obj[I[i]].kind == 1) pos.eb(i);
  //   }

  //   int K = len(pos) - 1;
  //   if (K < 0) continue;

  //   vc<ll> pre(K + 1), suf(K + 1), val(K + 1);

  //   FOR(t, K) {
  //     int a = I[pos[t]], b = I[pos[t] + 1];
  //     int dx = obj[b].l - obj[a].r;
  //     pre[t + 1] = pre[t] + dx;
  //   }

  //   suf[K] = 0;
  //   FOR_R(t, K) {
  //     int a = I[pos[t] + 1];
  //     int b = I[pos[t + 1]];
  //     int dx = obj[b].l - obj[a].r;
  //     suf[t] = suf[t + 1] + dx;
  //   }

  //   // 削除する価値
  //   FOR(x, K + 1) { val[x] = pre[x] + suf[x]; }
  //   CartesianTree<ll, true> CT(val);
  //   // val[x] が min になる区間を全部試す
  //   FOR(x, K + 1) {
  //     auto [lo, hi] = CT.range[x];
  //     FOR(a, lo, x + 1) FOR(b, x, hi) {
  //       ll v = val[x] - pre[a] - suf[b];
  //       int pa = pos[a], pb = pos[b];
  //       int L1 = (pa == 0 ? 0 : obj[I[pa - 1]].l + 1);
  //       int L2 = obj[I[pa]].l;

  //       int R1 = obj[I[pb]].r + 1;
  //       int R2 = (pb + 1 == m ? N : obj[I[pb + 1]].r);

  //       FOR(L, L1, L2 + 1) FOR(R, R1, R2 + 1) {
  //         if (parity[L] == 0 && parity[R] == 0 && H[L] <= lv && lv < H[R]) {
  //           // ANS[2] += v;
  //         }
  //       }
  //     }
  //   }
  // }

  // +-+-+-+
  {
    vc<int> cut(N + 2);
    FOR(i, N + 1) cut[i + 1] = cut[i] + (parity[i] == 0);

    FOR(lv, 2 * n + 1) {
      vc<int> &I = ids[lv];
      int m = len(I);
      if (m == 0) continue;

      vi pos;
      FOR(i, m) {
        if (obj[I[i]].kind == 1) pos.eb(i);
      }

      int K = len(pos) - 1;
      if (K < 0) continue;

      vc<ll> pre(K + 1), suf(K + 1), val(K + 1);

      FOR(t, K) {
        int a = I[pos[t]];
        int b = I[pos[t] + 1];
        int dx = obj[b].l - obj[a].r;
        pre[t + 1] = pre[t] + dx;
      }

      suf[K] = 0;
      FOR_R(t, K) {
        int a = I[pos[t] + 1];
        int b = I[pos[t + 1]];
        int dx = obj[b].l - obj[a].r;
        suf[t] = suf[t + 1] + dx;
      }

      FOR(x, K + 1) { val[x] = pre[x] + suf[x]; }
      vc<mint> LD(K + 1), RU(K + 1);

      FOR(a, K + 1) {
        int pa = pos[a];
        int L1 = (pa == 0 ? 0 : obj[I[pa - 1]].l + 1);
        int L2 = obj[I[pa]].l;
        LD[a] = cut[L2 + 1] - cut[L1];
      }

      FOR(b, K + 1) {
        int pb = pos[b];
        int R1 = obj[I[pb]].r + 1;
        int R2 = (pb + 1 == m ? N : obj[I[pb + 1]].r);
        RU[b] = cut[R2 + 1] - cut[R1];
      }

      vc<mint> SLD(K + 2), SLD_pre(K + 2);
      vc<mint> SRU(K + 2), SRU_suf(K + 2);

      FOR(i, K + 1) {
        SLD[i + 1] = SLD[i] + LD[i];
        SLD_pre[i + 1] = SLD_pre[i] + LD[i] * pre[i];
        SRU[i + 1] = SRU[i] + RU[i];
        SRU_suf[i + 1] = SRU_suf[i] + RU[i] * suf[i];
      }

      CartesianTree<ll, true> CT(val);

      FOR(x, K + 1) {
        auto [lo, hi] = CT.range[x];
        mint A0 = SLD[x + 1] - SLD[lo];
        mint A1 = SLD_pre[x + 1] - SLD_pre[lo];
        mint B0 = SRU[hi] - SRU[x];
        mint B1 = SRU_suf[hi] - SRU_suf[x];
        ANS[2] += mint(val[x]) * A0 * B0 - A1 * B0 - A0 * B1;
      }
    }
  }
  {
    // bad pair chain
    vc<int> cut(N + 2);
    FOR(i, N + 1) cut[i + 1] = cut[i] + (parity[i] == 0);

    vc<mint> LD(n), RU(n), LDs(n), RUs(n);
    vi left(n, -1), right(n, n);
    vc<int> same(n, 0);

    // LD, RU
    FOR(lv, 2 * n + 1) {
      const vc<int> &I = ids[lv];
      int m = len(I);
      FOR(i, m) {
        int x = I[i];
        if (obj[x].kind != 1) continue;
        int L1 = (i == 0 ? 0 : obj[I[i - 1]].l + 1);
        int L2 = obj[x].l;
        LD[x] = cut[L2 + 1] - cut[L1];

        LDs[x] = LD[x];
        if (i >= 2) LDs[x] += LDs[I[i - 2]];
      }

      FOR_R(i, m) {
        int x = I[i];
        if (obj[x].kind != 1) continue;
        int R1 = obj[x].r + 1;
        int R2 = (i + 1 == m ? N : obj[I[i + 1]].r);
        RU[x] = cut[R2 + 1] - cut[R1];

        RUs[x] = RU[x];
        if (i + 2 < m) RUs[x] += RUs[I[i + 2]];
      }
    }

    FOR(lv, 2 * n + 1) {
      vc<int> &I = ids[lv];
      int m = len(I);
      if (m == 0) continue;

      vi pos;
      FOR(i, m) {
        if (obj[I[i]].kind == 1) pos.eb(i);
      }

      int K = len(pos) - 1;
      if (K < 0) continue;

      vc<ll> pre(K + 1), suf(K + 1), val(K + 1);

      FOR(t, K) {
        assert(pos[t] + 1 < m);
        assert(pos[t + 1] == pos[t] + 2);
        assert(obj[I[pos[t]]].kind == 1);
        assert(obj[I[pos[t] + 1]].kind == 0);
        assert(obj[I[pos[t + 1]]].kind == 1);

        int a = I[pos[t]];
        int b = I[pos[t] + 1];
        ll dx = obj[b].l - obj[a].r;
        pre[t + 1] = pre[t] + dx;
      }

      suf[K] = 0;
      FOR_R(t, K) {
        assert(pos[t] + 1 < m);
        assert(pos[t + 1] == pos[t] + 2);

        int a = I[pos[t] + 1];
        int b = I[pos[t + 1]];
        ll dx = obj[b].l - obj[a].r;
        suf[t] = suf[t + 1] + dx;
      }
      FOR(x, K + 1) val[x] = pre[x] + suf[x];

      {
        vi st;
        FOR(x, K + 1) {
          while (len(st) && val[st.back()] > val[x]) POP(st);
          int a = I[pos[x]];
          if (len(st)) {
            int b = I[pos[st.back()]];
            left[a] = b;
            same[a] = (val[x] == val[st.back()]);
          }
          st.eb(x);
        }
      }
      {
        vi st;
        FOR_R(x, K + 1) {
          while (len(st) && val[st.back()] > val[x]) POP(st);

          int a = I[pos[x]];
          if (len(st)) {
            int b = I[pos[st.back()]];
            right[a] = b;
          }
          st.eb(x);
        }
      }
    }

    //
    vc<mint> dp(n);

    for (auto [l, r] : bad_range) {
      --r;  // closed
      assert(obj[l].kind == 1);
      assert(obj[r].kind == 1);

      int L = left[l];
      int R = right[r];

      mint XL = LDs[l];
      if (L != -1) {
        XL -= LDs[L];
        if (same[l]) XL += dp[L];
      }

      mint XR = RUs[r];
      if (R != n) {
        XR -= RUs[R];
      }

      ANS[3] += XL * XR;
      dp[r] = XL;
    }
  }

  return ANS;
}

mint solve_fixed_parity(ll N, ll M, vi A) {
  vc<int> I;
  FOR(i, N) if (popcnt(A[i]) % 2 == 1) I.eb(i);
  if (len(I) % 2 == 1) {
    N = POP(I);
    A.resize(N);
  }
  if (M % 2 == 0) return solve_fixed_parity_EVEN(N, M, A);

  assert(M % 2 == 1);
  vc<int> odd_cnt(N + 1);
  FOR(i, N) odd_cnt[i + 1] = odd_cnt[i] + (popcnt(A[i]) % 2);

  vi cut(N + 1);
  FOR(i, N + 1) cut[i] = (odd_cnt[i] % 2 == 0);

  // array<mint, 4> check;
  // {
  //   array<mint, 4> ANS{};
  //   FOR(R, N + 1) FOR(L, R) {
  //     if (cut[L] && cut[R]) {
  //       vi B = {A.begin() + L, A.begin() + R};
  //       auto S = single(R - L, M, B);
  //       FOR(i, 4) ANS[i] += S[i];
  //     }
  //   }
  //   check = ANS;
  // }

  array<mint, 4> ANS = many(N, M, A);
  // SHOW(check, ANS);
  // assert(ANS[0] == check[0]);
  // assert(ANS[1] == check[1]);
  // assert(ANS[2] == check[2]);
  // assert(ANS[3] == check[3]);

  return ANS[0] + ANS[1] * 2 + ANS[2] * 2 + ANS[3];
}

void solve() {
  LL(N, M);
  vi A(N);
  FOR(i, N) {
    STR(S);
    FOR(j, M) if (S[j] == 'O') A[i] |= 1 << j;
  }
  int k = 0;
  while (k < N && popcnt(A[k]) % 2 == 0) ++k;
  mint ANS = 0;
  ANS += solve_fixed_parity(N, M, A);
  if (k < N) {
    A = {A.begin() + k + 1, A.end()};
    ANS += solve_fixed_parity(N - k - 1, M, A);
  }
  print(ANS);
}

signed main() {
  INT(T);
  FOR(T) solve();
}