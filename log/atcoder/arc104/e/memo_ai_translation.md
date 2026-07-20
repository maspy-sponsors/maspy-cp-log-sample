> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - Random LIS

- Problem: [atcoder/arc104/e](https://atcoder.jp/contests/arc104/tasks/arc104_e)
- Problem Name: E - Random LIS
- difficulty: `5`
- tags: `N<=6` `lis数え上げ`
- tag_en: `N<=6` `counting LIS`
- id: `atcoder/arc104/e`
- logged_at: `2026-07-03`

## memo

This is a problem where, as long as the complexity does not depend on $\max A_i$, it is basically fine.

First, determine the $N!$ possible orders of the values to define the LIS. At this time, adopt a tie-breaking rule that among equal values, the one written further to the right has higher priority, so that the LIS is computed correctly.

After that, decide from which coordinate-compressed interval each term is chosen.

Split the problem into at most $720\times 462$ cases, and count each one in $O(N)$ time.
