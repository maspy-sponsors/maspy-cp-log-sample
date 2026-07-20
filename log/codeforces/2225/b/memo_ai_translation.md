> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B. Alternating String

- Problem: [codeforces/2225/b](https://codeforces.com/contest/2225/problem/B)
- Problem Name: B. Alternating String
- difficulty: `3`
- tags: []
- tag_en: []
- id: `codeforces/2225/b`
- logged_at: `2026-07-01`

## memo

It is far too easy to miss that, in the way this problem statement is written, "you are allowed to do it, but you don't have to do it" is added as a parenthetical note.

If we think about the strings that can be made and the operation patterns in that case, we can see that the operation positions only need to be considered among the endpoints and the positions related to places where $S[i] != S[i+1]$. If there are too many such positions, it is impossible; otherwise, I brute-forced over those places as candidates.
