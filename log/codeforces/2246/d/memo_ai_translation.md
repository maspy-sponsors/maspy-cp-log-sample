> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D. diss_quack and Array Game

- Problem: [codeforces/2246/d](https://codeforces.com/contest/2246/problem/D)
- Problem Name: D. diss_quack and Array Game
- difficulty: `4`
- tags: []
- tag_en: []
- id: `codeforces/2246/d`
- logged_at: `2026-07-13`

## memo

- The number of times Alice can choose the whole `$ /2` is the minimum lowbit.
- Otherwise: Bob makes it a state where there is an odd number in the second position, and Alice can only operate on the first element.

In the end,

- the cost `c_i` when operating on only one number
- the maximum `k` such that everything is divisible by `2^k`

are used, and the cost becomes something like `sum c_i - kN`.

`c_i` can be written roughly using `popcnt` and `topbit`.

Fix `K` and solve. For `a_i`, first increment it up to the smallest multiple of `2^K`, and then further increments are possible to make `c_i` smaller.

However, since the evaluation functions are things like `popcnt` and `topbit`, it is obviously wasteful to spend a large cost, so for this phase of incrementing, it is sufficient to search over an appropriate small range.
