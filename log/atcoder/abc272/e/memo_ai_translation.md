> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - Add and Mex

- Problem: [atcoder/abc272/e](https://atcoder.jp/contests/abc272/tasks/abc272_e)
- Problem Name: E - Add and Mex
- difficulty: `3`
- tags: `mex` `調和級数`
- tag_en: `mex` `harmonic series`
- id: `atcoder/abc272/e`
- logged_at: `2026-07-08`

## memo

The mex of $N$ non-negative integers is at most $N$.

It is enough to consider only $A_i$ such that $0\leq A_i\leq N$.

The number of pairs of such operation counts and $i$ is only $O(N\log N)$ by the harmonic series.
