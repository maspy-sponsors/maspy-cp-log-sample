> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. Build a Tree

- Problem: [codeforces/2247/e](https://codeforces.com/contest/2247/problem/E)
- Problem Name: E. Build a Tree
- difficulty: `4`
- tags: `構築` `木の構築` `順列の構築`
- tag_en: `construction` `tree construction` `permutation construction`
- id: `codeforces/2247/e`
- logged_at: `2026-07-19`

## memo

It can be constructed using only a path graph.

For a certain vertex,

- minus: "come from the right and exit to the right"
- plus: "come from the left and exit to the left"

Then, everything can be made with a structure like

`---00+000++`
