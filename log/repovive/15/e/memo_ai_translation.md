> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 15E. Synchronized Inversions

- Problem: [repovive/15/e](https://repovive.com/contests/15/problems/E)
- Problem Name: 15E. Synchronized Inversions
- difficulty: `3`
- tags: `転倒数`
- tag_en: `inversion count`
- id: `repovive/15/e`
- logged_at: `2026-07-06`

## memo

Since an adjacent swap changes the value by only `-2, 0, 2`, we can produce every value between the maximum and minimum with the same parity.

The maximum and minimum are achieved when `a` is sorted in ascending or descending order, respectively. This is simply because doing so is optimal for each pair individually.
