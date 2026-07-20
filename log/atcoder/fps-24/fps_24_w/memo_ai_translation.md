> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# W - 閉路

- Problem: [atcoder/fps-24/fps_24_w](https://atcoder.jp/contests/fps-24/tasks/fps_24_w)
- Problem Name: W - 閉路
- difficulty: `6`
- tags: `部分グラフ数え上げ` `SPS` `二重連結グラフ数え上げ` `SPS_exp`
- tag_en: `subgraph counting` `SPS` `biconnected graph counting` `SPS_exp`
- id: `atcoder/fps-24/fps_24_w`
- logged_at: `2026-07-02`

## memo

This is less about FPS and more about the appearance of SPS (set power series).

If you know how to count biconnected subgraphs, there is almost nothing new here.

- $G[S]$: the number of subgraphs whose vertex set is $S$
- $C[S]$: the number of connected graphs whose vertex set is $S$
- $B[S]$: the number of biconnected graphs whose vertex set is $S$

Then, $G = \exp C$. In this problem, $G$ is immediately known, so $C$ can be obtained from it.

To compute $B$ from $C$, follow the steps below.

- $F_0[S]$: the number of connected graphs whose vertex set is $S$
- $F_1[S]$: the number of connected graphs whose vertex set is $S$, where $0$ is not an articulation point
- $F_2[S]$: the number of connected graphs whose vertex set is $S$, where $0, 1$ are not articulation points
- $F_3[S]$: the number of connected graphs whose vertex set is $S$, where $0, 1, 2$ are not articulation points
- $\vdots$

What we want is to be able to compute $F_{r+1}$ from $F_r$, but it is probably easier to think about the reverse direction, computing $F_r$ from $F_{r+1}$. The only values that change are those containing $r$, and the computation is of the type of merging subgraphs that do not share any common vertices other than $r$. This computation is recognized as the $\exp$ of SPS.

Conversely, to obtain $F_{r+1}$ from $F_r$, we can take the SPS $\log$. Therefore, $B[S] = F_N[S]$ can be computed in $O(N^3\cdot 2^N)$ time by applying SPS $\log$ $N$ times.

On the other hand, by tracing this backward, we can also compute in the order $B[S] \to C[S] \to G[S]$. Doing this naively would just bring us back to where we started and would be meaningless, but it is fine if we modify the definitions as follows:

- $B'[S]$: the number of biconnected graphs whose vertex set is $S$, with the condition that vertices $0$ and $N-1$ do not belong to the same component with at least $3$ vertices
- $C'[S]$: the number of connected graphs whose vertex set is $S$, with the condition that vertices $0$ and $N-1$ do not belong to the same component with at least $3$ vertices
- $G'[S]$: the number of subgraphs whose vertex set is $S$, with the condition that vertices $0$ and $N-1$ do not belong to the same component with at least $3$ vertices

Then it is OK to follow the same computation procedure. By changing only some values of $B[S]` to `0`, we obtain $B'$, and then by computing $B' \to C' \to G'$, we get the answer.
