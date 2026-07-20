> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# N. BubbleSquare Tokens

- Problem: [codeforces/1423/n](https://codeforces.com/contest/1423/problem/N)
- Problem Name: N. BubbleSquare Tokens
- difficulty: `7`
- tags: `構築` `帰納的構成`
- tag_en: `construction` `inductive construction`
- id: `codeforces/1423/n`
- logged_at: `2026-07-14`

## memo

A somewhat difficult construction.

The policy of “add one vertex at a time and make it fit each time” is good, but it does not work naively.

For the later vertices, tentatively connect them with weight $1$. Under this state, for each $n$, make the first $n$ vertices become good.

Consider adding a new vertex $v$, and consider the edge $vw$ to an existing vertex $w$. At this time, since the edge weight is tentatively fixed to $1$,

- if $A[w]=0$: change $A[w]$ to $1$ and the edge weight to $0$.
- if $A[w]=1$: change $A[w]$ to $0$ and the edge weight to $2$.

This change operation is possible. In other words, while keeping the scores of existing vertices unchanged, you can adjust your own score. If the number of edges to existing vertices is $d$, then together with adjusting $A[v]$, $d+1$ kinds of adjustments are possible, so there are patterns that work well.
