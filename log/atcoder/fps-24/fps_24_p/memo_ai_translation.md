> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# P - ボール

- Problem: [atcoder/fps-24/fps_24_p](https://atcoder.jp/contests/fps-24/tasks/fps_24_p)
- Problem Name: P - ボール
- difficulty: `4`
- tags: `EGF` `多点評価`
- tag_en: `EGF` `multiple-point evaluation`
- id: `atcoder/fps-24/fps_24_p`
- logged_at: `2026-07-02`

## memo

The answer can be formulated as follows.

- The answer is $N![x^N]\prod_{0\leq i\leq m}f_i(x)$, where
  - $f_0(x)=\sum_{n=0}^{K}\frac{1}{n!}x^n$
  - $f_i(x)=\sum_{n=0}^{\infty}\frac{1}{n!}x^n=e^x$

Therefore, after a little rearrangement, the answer is $N![x^N]f_0(x)e^{mx}$.

From $e^{mx}=\sum_n\frac{m^n}{n!}x^n$, we can express the answer in the form of $\mathrm{polynomial}(m)$. After that, using multiple-point evaluation, it can be solved in $O(m\log^2 m+n\log n)$ time.
