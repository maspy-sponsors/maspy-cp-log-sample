> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D. Does anyone else hate the wind?

- Problem: [codeforces/1423/d](https://codeforces.com/contest/1423/problem/D)
- Problem Name: D. Does anyone else hate the wind?
- difficulty: `4`
- tags: []
- tag_en: []
- id: `codeforces/1423/d`
- logged_at: `2026-07-14`

## memo

This is a straightforward DP. The idea is to define `dp[day][row][col]` as the maximum possible HP.

This gives a time complexity like $O(NM\cdot \text{max day})$, but that is fine because `day` is bounded by `KT`.

As for where you end up when the wind blows, if you read the problem statement strictly and literally, I thought it might be slightly different. I think it is better to infer it by analogy.
