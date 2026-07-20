> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# O - 根付き木

- Problem: [atcoder/fps-24/fps_24_o](https://atcoder.jp/contests/fps-24/tasks/fps_24_o)
- Problem Name: O - 根付き木
- difficulty: `5`
- tags: `グラフ数え上げ` `ラグランジュ反転`
- tag_en: `graph counting` `Lagrange inversion`
- id: `atcoder/fps-24/fps_24_o`
- logged_at: `2026-07-02`

## memo

We will **ignore** the condition that the root is $1$, count everything, and finally divide by $N$.

Let $F(x)$ be the EGF of rooted trees. Then we can formulate it as follows:

$$F(x) = x\bigl(1+\sum_{p}\frac{1}{p!}F(x)^p\bigr)$$

Of course, the `1` term corresponds to the case where the root has $0$ children, and the $\frac{1}{p!}F(x)^p$ term corresponds to the case where the root has $p$ children.

Let us check the $p$-children case. To determine a rooted tree with $N$ vertices and $p$ children, we proceed as follows:

- Split $N=1+n_1+\cdots+n_p$.
- Partition the vertex set into sets $S_0,S_1,\ldots,S_p$ with $1,n_1,\ldots,n_p$ elements, respectively.
- Make each of the $n_i$-vertex sets into rooted trees.
- However, this would create the same rooted tree $p!$ times.

This is the idea.

Situations like “when trying to compute $F(x)$, $F(x)$ appears” occur especially often in counting rooted trees. This time, if we define $G(x)=\frac{1}{1+\sum_{p}\frac{1}{p!}x^p}$, then the condition becomes $G(F(x))=x$, so we can obtain the answer by computing the inverse function (in $O(N\log^2N)$ time), or by using Lagrange inversion (in $O(N\log N)$ time).
