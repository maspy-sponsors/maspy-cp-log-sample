> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14F. Connected Interval Prefixes

- Problem: [repovive/14/f](https://repovive.com/contests/14/problems/F)
- Problem Name: 14F. Connected Interval Prefixes
- difficulty: `7`
- tags: `区間dp` `区間を置いていくdp`
- tag_en: `interval dp` `dp for placing intervals`
- id: `repovive/14/f`
- logged_at: `2026-06-30`

## memo

For a valid permutation, focus on the places where the union interval grows.

Let

$$
I_1\subsetneq I_2\subsetneq \cdots \subsetneq I_k =[1,N]
$$

and let $C_j$ be the number of input intervals contained in $I_j$. Also, for each growth step, fix which interval is used to make it grow.

Then, for a fixed growth pattern, the count becomes

$$
(N-1)!\cdot \prod_{j=1}^{k-1}\frac{1}{N-C_j}
$$

or something like that. I derived this through some diligent algebraic manipulation, but the following interpretation is possible.

First, start from $(N-1)!$ ways with the first chosen interval already fixed. From there:

- among the $N-C_1$ intervals, the one used to grow to $I_2$ is at the front,
- among the $N-C_2$ intervals, the one used to grow to $I_3$ is at the front,
- $\vdots$

Such conditions are surprisingly independent. It is good to think of inserting small intervals into a sequence that satisfies the latter conditions.
