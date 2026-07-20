> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# I - スコア

- Problem: [atcoder/fps-24/fps_24_i](https://atcoder.jp/contests/fps-24/tasks/fps_24_i)
- Problem Name: I - スコア
- difficulty: `4`
- tags: `多項式総積`
- tag_en: `polynomial product`
- id: `atcoder/fps-24/fps_24_i`
- logged_at: `2026-07-02`

## memo

This is $[x^K]\prod_i(1+A_ix)$.

Such a product can be computed in $O(N\log^2 N)$ time by using a balanced computation procedure for the degrees, such as divide and conquer.
