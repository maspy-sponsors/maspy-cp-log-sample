> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14C. Range Reversal

- Problem: [repovive/14/c](https://repovive.com/contests/14/problems/C)
- Problem Name: 14C. Range Reversal
- difficulty: `4`
- tags: `区間反転`
- tag_en: `range reversal`
- id: `repovive/14/c`
- logged_at: `2026-06-30`

## memo

Let the numbers of `00` and `11` inside the interval be `a` and `b`.

First, since a reverse changes at most `2` pairs of adjacent relationships, the score is at least `a + b - 2`.

If both `a` and `b` are positive, this can be achieved by making the operation boundary at the place between `00` and `11`.

The only problematic case is when something like `a > 0, b = 0` holds. In this case, if we classify the reverse boundary into cases like

- between `00`
- between `01`
- between the ends of the interval and `#0`
- between the ends of the interval and `#1`

then it turns out that only when there is a `1` at an end can the score be decreased.
