> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# S - ゲーム

- Problem: [atcoder/fps-24/fps_24_s](https://atcoder.jp/contests/fps-24/tasks/fps_24_s)
- Problem Name: S - ゲーム
- difficulty: `6`
- tags: `Unvisited_Vertex_Geography` `最大マッチング` `オンライン畳み込み`
- tag_en: `Unvisited Vertex Geography` `maximum matching` `online convolution`
- id: `atcoder/fps-24/fps_24_s`
- logged_at: `2026-07-02`

## memo

### type 1
Construct an EGF like in Problem O, but prepare two types, such as $F_0(x), F_1(x)$, depending on the winner.

- $F_0(x)+F_1(x)=\sum_n\frac{n^{n-1}}{n!}x^n$ (the total number of labeled rooted trees)
- $F_0(x)=x\exp F_1(x)$

To compute this, it is enough if we can do the following:

- For $n=0,1,2,\ldots$, online, input $[x^n]F_1(x)$ and receive $[x^n]\exp F_1(x)$.

This becomes an online exp, but by using the fact that when $F=\exp f$, then $F'=f'F$, it reduces to online convolution. It can be solved in $O(N\log^2 N)$ time.

Apparently, it can also be made $O(N\log N)$ time with Newton's method.

### type 2
I wrote experiments without noticing it, but this game is a famous game that can be solved even on general graphs.

In the end, the task becomes counting trees that have a perfect matching.

This makes the decision problem solvable by a bottom-up tree DP, so if we express that in the same way as an EGF, that should work. However, before I noticed this, I solved it using experiments and OEIS.
