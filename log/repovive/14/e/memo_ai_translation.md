> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14E. Palindromic Not

- Problem: [repovive/14/e](https://repovive.com/contests/14/problems/E)
- Problem Name: 14E. Palindromic Not
- difficulty: `5`
- tags: `最短路問題` `最短路復元` `実験` `帰納的構成`
- tag_en: `shortest path problem` `shortest path reconstruction` `experiment` `inductive construction`
- id: `repovive/14/e`
- logged_at: `2026-06-30`

## memo

We do an experiment (construct an undirected graph with $2^N$ vertices and compute connectivity and shortest distances).

It seems that everything can be done if $N \geq 4$.

For example, if $N = 4M$, I considered solving the length-4 part $M$ times, but it seems that when $N = 4$, there are cases that take 6 moves.

Instead, it turns out that when $N = 5$, it can always be done in at most 4 moves.
So when $N$ is huge, it is enough to "solve the last 5 characters in at most 4 moves and reduce to the case of $N-5$".

Since the number of test cases $t$ is small, once $N \leq 8$ or so, I think it is fine to spend about $O(2^N\cdot polynomial(N))$ time on a rough solution.
