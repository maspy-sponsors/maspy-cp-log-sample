> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - 数列 3

- Problem: [atcoder/fps-24/fps_24_e](https://atcoder.jp/contests/fps-24/tasks/fps_24_e)
- Problem Name: E - 数列 3
- difficulty: `4`
- tags: `EGF`
- tag_en: `EGF`
- id: `atcoder/fps-24/fps_24_e`
- logged_at: `2026-07-02`

## memo

If the occurrence counts are $c_1,c_2,\ldots$, this becomes a problem of summing $\frac{N!}{c_1!\cdots c_M!}$ over the appropriate range. The appropriate range is $\sum c_i=M$ and $0\leq c_i\leq i$, and taking this into account, the answer can be formulated as follows.

$$N!\cdot [x^M]\prod_i \sum_{c=0}^i\frac{x^c}{c!}$$
