> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# M - 連結グラフ

- Problem: [atcoder/fps-24/fps_24_m](https://atcoder.jp/contests/fps-24/tasks/fps_24_m)
- Problem Name: M - 連結グラフ
- difficulty: `4`
- tags: `グラフ数え上げ` `FPS_exp`
- tag_en: `graph counting` `formal power series exponential`
- id: `atcoder/fps-24/fps_24_m`
- logged_at: `2026-07-02`

## memo

Let $A(x)$ be the EGF of connected graphs, and let $B(x)$ be the EGF of arbitrary graphs (when the counts are $a_n, b_n$, this means $\sum \frac{a_n}{n!}x^n$ and $\sum \frac{b_n}{n!}x^n$).

Then, almost in the same way as in L, we can see that $B(x)=\exp A(x)$.

This time, $B(x)$ is easy to obtain, and we want to know $A$ given $B$. This can be computed as $A(x)=\log B(x)$.
