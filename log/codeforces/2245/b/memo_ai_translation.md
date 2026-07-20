> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B. Delete and Concatenate

- Problem: [codeforces/2245/b](https://codeforces.com/contest/2245/problem/B)
- Problem Name: B. Delete and Concatenate
- difficulty: `4`
- tags: []
- tag_en: []
- id: `codeforces/2245/b`
- logged_at: `2026-07-17`

## memo

First, after subtracting `c` from each element, we may assume that the operation cost is `0`.

Consider the feasible `01` strings when we set the elements to be "taken" as `1` and the elements to be "not taken" as `0`.

Then, a necessary condition appears: the number of `1`s is at least the number of `0`s.
This is also sufficient, and it can be achieved by repeatedly deleting either `01` or `10` as long as there is a `0`.
