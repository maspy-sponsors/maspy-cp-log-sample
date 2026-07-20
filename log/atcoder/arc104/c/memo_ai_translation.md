> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C - Fair Elevator

- Problem: [atcoder/arc104/c](https://atcoder.jp/contests/arc104/tasks/arc104_c)
- Problem Name: C - Fair Elevator
- difficulty: `4`
- tags: []
- tag_en: []
- id: `atcoder/arc104/c`
- logged_at: `2026-07-03`

## memo

This means arranging intervals of the form `[0,n], [1,n+1], ..., [n-1,2n-1]`.

Define an interval `[L,R]` to be good if people can be assigned to that interval properly; then the task is to divide the whole range into good intervals.
