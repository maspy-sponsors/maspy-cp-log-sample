> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C. Tree and Array

- Problem: [codeforces/398/c](https://codeforces.com/contest/398/problem/C)
- Problem Name: C. Tree and Array
- difficulty: `7`
- tags: `帰納的構築`
- tag_en: `inductive construction`
- id: `codeforces/398/c`
- logged_at: `2026-07-08`

## memo

If we can create a structure such that adding $2n$ vertices increases the number of good pairs by $n$, that is enough.

When a tree with $N$ vertices has vertex $N$ not used in any good pair, we want to construct a tree with $N+2n$ vertices in which vertex $N+2n$ is also not used in any good pair. This can be done if we have an appropriate $2n$-vertex part.

After that, it is a search. It turns out that if $N$ is sufficiently large, we can increase it by $8$ vertices, and for small cases we found and embedded them by random search. (If you search in a fairly small range of $t$ values, you can find quite a lot of solutions.)
