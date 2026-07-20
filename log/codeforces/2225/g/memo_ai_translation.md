> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G. Simple Problem

- Problem: [codeforces/2225/g](https://codeforces.com/contest/2225/problem/G)
- Problem Name: G. Simple Problem
- difficulty: `6`
- tags: `整数論` `構築`
- tag_en: `number theory` `construction`
- id: `codeforces/2225/g`
- logged_at: `2026-07-02`

## memo

[Unproved part included]

The idea is to prove by induction that if the numbers are pairwise coprime, then a path can be created from any starting point.

Let the greatest common divisor after the first $n-1$ numbers be $g$, and let the $n$-th number be $c$.
If $g=1$, then the property is already satisfied by the first $n-1$ numbers.

- Build a path over all $x$ such that $x\equiv 0\pmod{g}$
- Build a path over all $x$ such that $x\equiv c\pmod{g}$
- Build a path over all $x$ such that $x\equiv 2c\pmod{g}$

and then connect them.
For moving between the paths, use $x\to x+c$.

At this point, the requirement is that $x+c<N$.
I have not verified whether this is always okay, but if I minimize the endpoint of the path in the base step of the induction, then it will probably be fine? With that assumption, it passed (I have not proved it properly).
