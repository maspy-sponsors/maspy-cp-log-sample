> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D - Angst for All Pairs

- Problem: [atcoder/arc224/d](https://atcoder.jp/contests/arc224/tasks/arc224_d)
- Problem Name: D - Angst for All Pairs
- difficulty: `3`
- tags: []
- tag_en: []
- id: `atcoder/arc224/d`
- logged_at: `2026-07-12`

## memo

Rather than looking at the numbers on the cards, consider, for each $x\in [1,K]$, the set of cards on which $x$ is written.

Then this simply becomes: “Assign a distinct set to each $x$.”

Prepare $K$ sets with small popcnt, and assign smaller sets to numbers with larger cost.
