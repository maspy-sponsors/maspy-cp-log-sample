> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C. 0mar and Alternating Sums

- Problem: [codeforces/2246/c](https://codeforces.com/contest/2246/problem/C)
- Problem Name: C. 0mar and Alternating Sums
- difficulty: `4`
- tags: []
- tag_en: []
- id: `codeforces/2246/c`
- logged_at: `2026-07-13`

## memo

It is rather complicated.

First, consider the patterns where we take an even number of elements from the whole array.

By dividing it as

+-/+-/+-

we can see that the total sum is at most $0$. Then, for the total sum to be $0$, it must be the case that they are matched in pairs of $2$.

Next, consider the patterns where we take an odd number of elements from the whole array.

If we divide it as

+/-+/-+/-+/

then the contribution to the alternating sum from blocks other than the first one is nonnegative. Therefore, only patterns like

-1, [a,a], [b,b], ..., [c,c], [x,x+1], [d,d], [e,e], ...

are possible. For each fixed $x$, we do an appropriate calculation.
