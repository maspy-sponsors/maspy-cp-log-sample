> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14A. Odd Sum Game

- Problem: [repovive/14/a](https://repovive.com/contests/14/problems/A)
- Problem Name: 14A. Odd Sum Game
- difficulty: `1`
- tags: []
- tag_en: []
- id: `repovive/14/a`
- logged_at: `2026-06-30`

## memo

If $k < n$, then the answer is Yes. Take the smallest $k$ elements, and if that does not work, you can make it work by shifting one maximum value.

So it is enough to solve the case $k=n$, where you have no choice but to select everything, so just determine whether that works.
