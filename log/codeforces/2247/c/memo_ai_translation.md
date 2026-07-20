> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C. Inversion of a Subsequence

- Problem: [codeforces/2247/c](https://codeforces.com/contest/2247/problem/C)
- Problem Name: C. Inversion of a Subsequence
- difficulty: `3`
- tags: []
- tag_en: []
- id: `codeforces/2247/c`
- logged_at: `2026-07-19`

## memo

The input can be compressed into the counts of $(0,0)$, $(0,1)$, $(1,0)$, and $(1,1)$.

First, determine whether it can be done in $0$ moves. Check whether $\sum A = 0$ and $\sum B = N$.

If the number of $(0,1)$ pairs is odd, then it takes $1$ move. Since for the other indices, we may include only the necessary ones in the operation as desired.

Otherwise, it takes $2$ moves. With a little case analysis, we can check whether it can be transformed into a state where the number of $(0,1)$ pairs is odd.
