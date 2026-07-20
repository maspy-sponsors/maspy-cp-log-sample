> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G - Sum of Mex of Mod of Linear

- Problem: [atcoder/abc465/g](https://atcoder.jp/contests/abc465/tasks/abc465_g)
- Problem Name: G - Sum of Mex of Mod of Linear
- difficulty: `5`
- tags: `差分更新` `実装`
- tag_en: `difference update` `implementation`
- id: `atcoder/abc465/g`
- logged_at: `2026-07-04`

## memo

Basically, this is an implementation problem. It is somewhat hard.

As a point, for a certain $i$, it is enough to consider only those $k$ such that $Ck + A_i \equiv 0$.
This is because the mex becomes $0$ at all other positions.

For each $x$,

- $cnt[x]$: the number of $k$ such that $Ck + x \equiv 0$.
- $mex[x]$: the mex at the time when $Ck + x \equiv 0$.
- $ans[x]$: $cnt[x] \times ans[x]$

and we manage $ANS = \sum_x ans[x]$.

When $x$ is removed and $y$ is added, roughly the update targets are $x$ itself, or $y$ such that $mex[y] = x - y$.

By preparing prefix-sum tables for $cnt[x]$ and for $cnt[x] \times x$, differential updates can be performed quickly.

I implemented this by performing coordinate compression using as references the values $x$ that can appear as $A_i$ at some time, and also $x+1$ for such $x$.
