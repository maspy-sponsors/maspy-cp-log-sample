# Q - サイコロ

- 問題: [atcoder/fps-24/fps_24_q](https://atcoder.jp/contests/fps-24/tasks/fps_24_q)
- 問題名: Q - サイコロ
- difficulty: `5`
- tags: `k乗和列挙`
- id: `atcoder/fps-24/fps_24_q`
- logged_at: `2026-07-02`

## memo

計算すべきは次の値です．

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{i,j}(A_i+B_j)^k$$

素直に二項定理で展開すると，

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{d=0}^k\binom{k}{d}\sum_{i}A_i^d\sum_{j}B_j^{k-d}$$

となります．そこで $a_d = \sum_{i}A_i^d$, $b_d=\sum_jB_j^d$ とすれば，

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{d=0}^k\binom{k}{d}a_db_{n-d}$$

です．よって $a_0,\ldots,a_K$ と $b_0,\ldots,b_K$ が求まれば，答は適当な畳み込みで求まります．

$a_d$ を列挙するには，次を使えばよいです： $\sum_da_dx^d=\sum_i\frac{1}{1-A_ix}$．

この有理式を分母分子の多項式の組として計算します．これは分割統治で $O(N\log^2)$ 時間でできます．そのあとで係数列を求めればよいです．
