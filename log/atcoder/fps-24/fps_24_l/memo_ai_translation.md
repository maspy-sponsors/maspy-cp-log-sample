> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# L - 順列 2

- Problem: [atcoder/fps-24/fps_24_l](https://atcoder.jp/contests/fps-24/tasks/fps_24_l)
- Problem Name: L - 順列 2
- difficulty: `4`
- tags: `サイクル分解` `グラフ数え上げ` `FPS_exp`
- tag_en: `cycle decomposition` `graph counting` `FPS_exp`
- id: `atcoder/fps-24/fps_24_l`
- logged_at: `2026-07-02`

## memo

If we think of a permutation as a functional graph, we get the following.

- Count directed graphs with $N$ vertices such that each connected component is a cycle of at least $3$ vertices.

To obtain this, do the following.

- Take $k_1,\ldots,k_m \ge 3$ such that $N=k_1+k_2+\cdots+k_m$.
- Partition an $N$-element set into sets $S_1,\ldots,S_m$ with $k_1,\ldots,k_m$ elements. (A multinomial coefficient appears.)
- Turn each $S_i$ into a directed cycle.
- However, with this method, the same graph is created $m!$ times (permutations of the labels of the sets).

Let $a_n$ be the number of ways to make $n$ vertices into a cycle, and let $A(x)=\sum_n\frac{a_n}{n!}x^n$. Then the answer can be formulated as follows:

$$N![x^N]\sum_m \frac{1}{m!}A(x)^m=N![x^N]\exp A(x)$$

The $N!$ and the denominator $n!$ in the definition of $A(x)$ come from the multinomial coefficient. The $\frac{1}{m!}$ appears because the same graph is created $m!$ times. In the end, computing the $\exp$ is the essence, and the problem can be solved in $O(N\log N)$ time.
