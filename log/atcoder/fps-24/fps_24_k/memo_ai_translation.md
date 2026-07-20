> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# K - 順列

- Problem: [atcoder/fps-24/fps_24_k](https://atcoder.jp/contests/fps-24/tasks/fps_24_k)
- Problem Name: K - 順列
- difficulty: `4`
- tags: `indecomposable_permutations`
- tag_en: `indecomposable permutations`
- id: `atcoder/fps-24/fps_24_k`
- logged_at: `2026-07-02`

## memo

When deriving a counting relation, there is a technique of considering how to decompose “arbitrary objects” into “indecomposable objects” (the later example of counting connected graphs is the same kind of idea).

For an arbitrary permutation, we can think of a segment `[l, r]` as an indecomposable interval if `p_l, \ldots, p_r` are equal as a multiset to `l, \ldots, r`, and consider its indecomposable decomposition.

$$1,2,4,3,7,5,6 → |1|2|4,3|7,5,6|$$

Then, “an arbitrary permutation” corresponds to choosing a partition `(k_1, k_2, \ldots, k_m)` such that $k_1+k_2+\cdots+k_m=n$, and determining an indecomposable permutation of length $k_i$ for each part.

If we let the generating function of “arbitrary permutations” be $F(x)$ and the generating function of “indecomposable permutations” be $G(x)$, then we obtain the relation $F(x)=\sum_mG(x)^m$. Therefore, $F(x)=\frac{1}{1-G(x)}$.

Since $F(x)$ is easy to determine, $G(x)$ can also be determined from it.
