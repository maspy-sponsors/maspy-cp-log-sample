> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# Q - サイコロ

- Problem: [atcoder/fps-24/fps_24_q](https://atcoder.jp/contests/fps-24/tasks/fps_24_q)
- Problem Name: Q - サイコロ
- difficulty: `5`
- tags: `k乗和列挙`
- tag_en: `k-th power sum enumeration`
- id: `atcoder/fps-24/fps_24_q`
- logged_at: `2026-07-02`

## memo

The value to compute is the following:

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{i,j}(A_i+B_j)^k$$

If we expand this straightforwardly using the binomial theorem, we get

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{d=0}^k\binom{k}{d}\sum_{i}A_i^d\sum_{j}B_j^{k-d}$$

So if we let $a_d = \sum_{i}A_i^d$ and $b_d=\sum_jB_j^d$, then

$$\mathrm{ANS}[k]=\frac{1}{NM}\sum_{d=0}^k\binom{k}{d}a_db_{n-d}$$

holds.

Therefore, if we can find $a_0,\ldots,a_K$ and $b_0,\ldots,b_K$, the answer can be obtained by an appropriate convolution.

To enumerate $a_d$, we can use the following: $\sum_da_dx^d=\sum_i\frac{1}{1-A_ix}$.

We compute this rational function as a pair of denominator and numerator polynomials. This can be done in $O(N\log^2)$ time by divide and conquer. After that, we only need to obtain the coefficient sequence.
