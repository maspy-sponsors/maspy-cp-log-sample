> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 15D. Distant Transfers

- Problem: [repovive/15/d](https://repovive.com/contests/15/problems/D)
- Problem Name: 15D. Distant Transfers
- difficulty: `3`
- tags: `exchange_argument`
- tag_en: `exchange argument`
- id: `repovive/15/d`
- logged_at: `2026-07-06`

## memo

Think of matching the excess on $l$ with the deficit on $r$.

If one index can serve as both a deficit and an excess, then we may eliminate it.

Then, it is optimal to sort the excesses and deficits by increasing index, and match them in that order as they are.
If there is an inverted pair, eliminating it does not make the score worse.
