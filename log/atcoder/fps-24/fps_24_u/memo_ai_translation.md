> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# U - 録画機

- Problem: [atcoder/fps-24/fps_24_u](https://atcoder.jp/contests/fps-24/tasks/fps_24_u)
- Problem Name: U - 録画機
- difficulty: `7`
- tags: `多項式行列積`
- tag_en: `polynomial matrix multiplication`
- id: `atcoder/fps-24/fps_24_u`
- logged_at: `2026-07-02`

## memo

First, for the feasibility condition, at any moment there must be at most $2$ machines.

As for how to construct $A$ and $B$, think of it as:

- decide the multiset $A$
- decide the multiset $B$
- match $A$ and $B$

Count in increasing order of time.

- When placing an $A$, do not assign a label (query index). The label will be fixed at the end by attaching the multinomial coefficient.
- When placing a $B$, decide which $A$ it is matched with.

That is the idea. For the condition “at most 2 machines,” we can treat it by considering a broken-line graph like the prefix sums of a parenthesis sequence, with the height always within $[0,2]$.

Instead of attaching the final multinomial coefficient at the end, for the denominator part of the multinomial coefficient, attach it according to the number of $A$'s placed at the same coordinate.

If we do these things carefully, the problem can be rewritten as follows:

- Given a $(3,3)$ matrix $F$ whose entries are polynomials of degree at most $2$, compute $[x^N]F^t$ for $t=1,2,3,\ldots,U$.

Although $F$ is a matrix, the handling is almost the same as for an ordinary polynomial. It can be computed in $O(N\log ^2 N)$ time by divide and conquer.
