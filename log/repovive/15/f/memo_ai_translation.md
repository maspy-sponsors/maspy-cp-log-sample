> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 15F. Magnetic Path

- Problem: [repovive/15/f](https://repovive.com/contests/15/problems/F)
- Problem Name: 15F. Magnetic Path
- difficulty: `4`
- tags: []
- tag_en: []
- id: `repovive/15/f`
- logged_at: `2026-07-06`

## memo

Basically, make them approach each other by distance $2$ at a time, but when $N$ is odd, stop one of them once and then advance.

I computed it with DP using the pair of positions of the two vertices as the state. I pruned states where the distance is not decreasing relative to the number of steps.
