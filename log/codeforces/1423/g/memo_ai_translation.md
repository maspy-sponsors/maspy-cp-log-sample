> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G. Growing flowers

- Problem: [codeforces/1423/g](https://codeforces.com/contest/1423/problem/G)
- Problem Name: G. Growing flowers
- difficulty: `7`
- tags: `区間種類数` `実装`
- tag_en: `number of distinct values in a range` `implementation`
- id: `codeforces/1423/g`
- logged_at: `2026-07-14`

## memo

Since this is a number-of-distinct-values-in-a-range problem, first consider

prev[i] := max j such that A[j]=A[i]

Considering the set of pairs `(prev[i], i)` as a whole, interval constant-assignment queries become additions/removals that are amortized $O(N+Q)$ times.

While performing these additions/removals of pairs, next consider how `ANS[K]` for each $K$ changes. Then we see that the contribution of a fixed `(i, j)` to `ANS[K]` becomes a linear function of $K$ for each interval of $K$.

In other words, it can be represented by range additions on arrays `a, b` such that `ANS[K] = a[K] \cdot K + b[K]`.
