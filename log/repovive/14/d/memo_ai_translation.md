> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14D. Sleeping Journey

- Problem: [repovive/14/d](https://repovive.com/contests/14/problems/D)
- Problem Name: 14D. Sleeping Journey
- difficulty: `4`
- tags: `BFS`
- tag_en: `BFS`
- id: `repovive/14/d`
- logged_at: `2026-06-30`

## memo

First, compute the distance from each point. Think of each vertex as having this value written on it, and you can forget the graph structure.

The actions are: decrease by $-1$, or draw a random value from among $N$ values.

You should examine the pattern where if $x\leq K$ then do $-1$, and if $K < x$ then draw.

Take mod only at the end; comparisons in the middle are rational-number comparisons.
