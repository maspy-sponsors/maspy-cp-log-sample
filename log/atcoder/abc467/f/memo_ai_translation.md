> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F - Email Scheduling Optimization

- Problem: [atcoder/abc467/f](https://atcoder.jp/contests/abc467/tasks/abc467_f)
- Problem Name: F - Email Scheduling Optimization
- difficulty: `4`
- tags: `ソート順の決定` `値をインデックスにする`
- tag_en: `determining sort order` `use values as indices`
- id: `atcoder/abc467/f`
- logged_at: `2026-07-18`

## memo

By considering the order of the pairs $(A_1,B_1),(A_2,B_2)$, we find that it is optimal to sort by $B$ in descending order.

For a sequence sorted in descending order, the answer can be computed with a segment tree.

By coordinate-compressing all values in advance, all processing can be done with a segment tree that uses the value of $B_i$ as the index.
