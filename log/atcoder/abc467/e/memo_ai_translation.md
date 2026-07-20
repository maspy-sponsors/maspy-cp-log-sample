> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - Adjacent Sums (hard)

- Problem: [atcoder/abc467/e](https://atcoder.jp/contests/abc467/tasks/abc467_e)
- Problem Name: E - Adjacent Sums (hard)
- difficulty: `4`
- tags: []
- tag_en: []
- id: `atcoder/abc467/e`
- logged_at: `2026-07-18`

## memo

For the number of additions $(x_i)$ (considered modulo $M$), there is a constraint on how many times $x_i+x_{i+1}$ occurs.

If we take one (not necessarily optimal) solution, then

- $+c$ to $x_i$ at odd indices
- $-c$ to $x_i$ at even indices

gives all solutions. I think we optimize over $c$.

Viewed as a function of $c$, it is piecewise linear, so it is enough to compute only the boundaries where something happens.
After that, it can be handled with sorting or binary search.
