> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D - 数列 2

- Problem: [atcoder/fps-24/fps_24_d](https://atcoder.jp/contests/fps-24/tasks/fps_24_d)
- Problem Name: D - 数列 2
- difficulty: `4`
- tags: []
- tag_en: []
- id: `atcoder/fps-24/fps_24_d`
- logged_at: `2026-07-02`

## memo

If we consider the movement $0\to a_1\to a_2\to \cdots \to a_N\to M$,

the problem becomes to make $M$ as the sum of

- a non-negative integer
- $N-1$ positive odd integers
- a non-negative integer

Therefore, this is a problem of finding

$$[x^M]\frac{1}{1-x}\cdot \left(\frac{x}{1-x^2}\right)^{N-1}\cdot \frac{1}{1-x}$$

For example, after computing the middle $(N-1)$-th power, it can be implemented as two prefix sums.
