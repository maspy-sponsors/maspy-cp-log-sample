> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B. ezraft and Array

- Problem: [codeforces/2246/b](https://codeforces.com/contest/2246/problem/B)
- Problem Name: B. ezraft and Array
- difficulty: `3`
- tags: `構築` `帰納的構成`
- tag_en: `construction` `inductive construction`
- id: `codeforces/2246/b`
- logged_at: `2026-07-13`

## memo

Let the sum be $S$, and define $b_i=S/a_i$; then $\sum 1/b_i=1$.

I think this is a problem of controlling the LCM and constructing such unit fractions.

It can be built roughly as follows.

- If we try $2,4,8,16,32,32$, then although this is not distinct, the sum of reciprocals is $1$.
- If we use $2,4,8,16,32,48,96$, then they are distinct and the sum of reciprocals is $1$.

The only impossible case is $N=2$; otherwise, use the method above.
