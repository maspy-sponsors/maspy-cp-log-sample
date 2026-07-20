> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D - Multiset Mean

- Problem: [atcoder/arc104/d](https://atcoder.jp/contests/arc104/tasks/arc104_d)
- Problem Name: D - Multiset Mean
- difficulty: `4`
- tags: `戻すdp`
- tag_en: `rerooting dp`
- id: `atcoder/arc104/d`
- logged_at: `2026-07-03`

## memo

We count the ways to make the sum `0` after subtracting by `x`.

If we think about difference updates with respect to `x`, this means deleting an integer of a certain value and adding an integer of a certain value.

If we think in terms of generating functions, we can write it as a rational function of the form `\frac{1-x^{n(K+1)}}{1-x}`, and then obtain the appropriate coefficient while multiplying and dividing.
