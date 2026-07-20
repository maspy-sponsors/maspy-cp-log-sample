> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 15G. Complementary Path

- Problem: [repovive/15/g](https://repovive.com/contests/15/problems/G)
- Problem Name: 15G. Complementary Path
- difficulty: `6`
- tags: `ハミルトンパス構築`
- tag_en: `Hamiltonian path construction`
- id: `repovive/15/g`
- logged_at: `2026-07-06`

## memo

A Hamiltonian path construction problem in the complement graph of a triangle-free graph.

The implementation ended up being difficult.

Assume $N \geq 3$. First, it is necessary that a path of length $2$ can be made. Also, connectivity is necessary.

These are also sufficient conditions.

Take a maximal path, and suppose it is not yet a Hamiltonian path. Let its start be $s$ and its end be $t$.
If there is an unused neighbor of $s$ or $t$, then the path can be extended, a contradiction.

Otherwise, it is currently a cycle. By connectivity, there is an edge from some point on the cycle to an unused vertex, so after rotating the path so that that vertex becomes an endpoint, we extend the path.

We need to support rotating a sequence and adding to both ends. I thought this could be done with something like a doubly linked list, but for safe implementation I ended up bringing in a balanced binary tree.
