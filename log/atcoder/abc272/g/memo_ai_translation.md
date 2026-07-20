> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G - Yet Another mod M

- Problem: [atcoder/abc272/g](https://atcoder.jp/contests/abc272/tasks/abc272_g)
- Problem Name: G - Yet Another mod M
- difficulty: `4`
- tags: `乱択`
- tag_en: `randomized`
- id: `atcoder/abc272/g`
- logged_at: `2026-07-08`

## memo

If we fix one optimal solution, the probability that randomly chosen $i,j$ correspond to it is about $1/4$.

We randomize a sufficient number of times. As candidates for $M$, it is enough to consider only the divisors of that difference, and we try them.
