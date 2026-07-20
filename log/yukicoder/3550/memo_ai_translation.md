> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# No.3550 Another Rurumaru Function Problem

- Problem: [yukicoder/3550](https://yukicoder.me/problems/no/3550)
- Problem Name: No.3550 Another Rurumaru Function Problem
- difficulty: `4`
- tags: []
- tag_en: []
- id: `yukicoder/3550`
- logged_at: `2026-07-14`

## memo

Determine the answer digit by digit from the most significant digit.

Fix the target digit that must be `1` and check it.
If the target even digit is `1`, then the `A_i` used are also limited to numbers of that kind.
Use all such numbers and check whether the odd digits are fine.
