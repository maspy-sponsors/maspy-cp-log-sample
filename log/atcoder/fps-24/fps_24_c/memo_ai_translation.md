> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C - 数列

- Problem: [atcoder/fps-24/fps_24_c](https://atcoder.jp/contests/fps-24/tasks/fps_24_c)
- Problem Name: C - 数列
- difficulty: `3`
- tags: []
- tag_en: []
- id: `atcoder/fps-24/fps_24_c`
- logged_at: `2026-07-02`

## memo

It can be formulated as $[x^S](1+x+\cdots+x^{M})^N$.

You can either use the fps pow library as is, or rewrite it as $(1-x^{M+1})^N\cdot (1-x)^{-N}$ and then use the binomial theorem and the negative binomial theorem.

These methods solve it in $O(S\log S)$ time and $O(S)$ time, respectively.
