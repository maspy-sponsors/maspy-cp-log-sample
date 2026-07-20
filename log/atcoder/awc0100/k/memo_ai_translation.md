> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# K - 商店街の区画選び

- Problem: [atcoder/awc0100/k](https://atcoder.jp/contests/awc0100/tasks/awc0100_k)
- Problem Name: K - 商店街の区画選び
- difficulty: `4`
- tags: `平方分割` `KD_tree`
- tag_en: `square root decomposition` `KD tree`
- id: `atcoder/awc0100/k`
- logged_at: `2026-06-28`

## memo

First, let us think of a type $2$ query as a problem of choosing one of the $1 \leq i \leq N-K+1$ choices, where choice $i$ is $[i,i+K)$.
Let $n=N-K+1$, and manage the information of the $n$ kinds of choices.

If we denote the total rent of the $i$-th choice by $B_i$ and the total parking-space count by $D_i$, then it becomes something like:

- interval addition to $B_i$
- query the minimum value of $B_i$ among $i$ such that $D_i\geq X_j$

Another way to view it is as a 2D rectangle query: consider points $(i, D_i)$, and then we get interval addition in the $x$ direction and interval max in the $y$ direction.
For rectangle queries, processing like addition and max is usually difficult to make as fast as $o((N+Q)^{1.5})$.

https://drive.google.com/file/d/1bSjYiA-nSsHzBbCnLq1GeTpRzs2Ucm0q/view

With square root decomposition, using the fact that the range of $X_i$ is small, we get $1.5$-power complexity.
Square root decomposition tends to become a TL battle, so it is good to carefully examine things like whether the binary search log can be eliminated.

However, I used a KD tree that can do addition and max for rectangles.
KD trees often have a larger constant factor than column-wise square root decomposition, but it was fine.
