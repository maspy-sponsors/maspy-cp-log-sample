> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# T - カラフル

- Problem: [atcoder/fps-24/fps_24_t](https://atcoder.jp/contests/fps-24/tasks/fps_24_t)
- Problem Name: T - カラフル
- difficulty: `6`
- tags: `包除原理`
- tag_en: `inclusion-exclusion principle`
- id: `atcoder/fps-24/fps_24_t`
- logged_at: `2026-07-02`

## memo

Sequences satisfying the conditions can be obtained by arranging the following in order:

- point $1$
- a positive-length vertex sequence of the other colors
- repeating the combination of (a vertex of color 1, a positive-length vertex sequence of the other colors) a nonnegative number of times
- point $1$ at the end

To prepare for $A_1=998244353$, this is written in a slightly redundant form (you cannot just write only the 1st and 3rd items and divide by $A_i$ at the end).

If we denote by $F(x)$ the generating function of the “positive-length vertex sequences of the other colors,” then the answer is expressed as

$$[x^{T-1}]F(x)\cdot \sum_{m=0}^{\infty}(A_1x\cdot F(x))^m = \frac{F(x)}{1-A_1xF(x)}$$

The conclusion is that $F(x)$ is a rational function of degree $O(N)$, and therefore the generating function of the answer is also such a rational function (the answer can be found in $O(N\log N\log T)$ time). Let us find $F(x)$.

We use the inclusion-exclusion principle. That is, for some moves, we count sequences with a mark meaning “move to the same color” with weight $-1$.

If we bundle together vertices connected by marks, the result is as follows.

- To count a “positive-length vertex sequence of the other colors” of length $N$
  - partition $N=n_1+n_2+\cdots+n_m$ into positive integers, and
  - within each block, create a vertex sequence consisting only of moves to the same color, and weight it by $-1$ for each move

The generating function for this block is, by considering each color separately, the alternating sum
$\sum_{i} (A_ix-A_ix^2+A_ix^3-A_ix^4\pm\cdots)$.
Since this is a sum of rational functions, it is a rational function.
