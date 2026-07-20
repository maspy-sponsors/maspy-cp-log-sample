> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G - 硬貨

- Problem: [atcoder/fps-24/fps_24_g](https://atcoder.jp/contests/fps-24/tasks/fps_24_g)
- Problem Name: G - 硬貨
- difficulty: `4`
- tags: `戻すdp`
- tag_en: `rollback dp`
- id: `atcoder/fps-24/fps_24_g`
- logged_at: `2026-07-02`

## memo

Consider a DP table $\dp[n]$ counting the number of ways to pay exactly $n$ yen ($0\leq n\leq N$); it is enough to be able to add and remove a coin of some value.

Deletion is a bit unintuitive to handle, but if we think in terms of FPS, addition is simply multiplying by $\frac{1}{1-x^a}$, so deletion can be implemented by multiplying by $(1-x^a)$.
