> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F - Two Strings

- Problem: [atcoder/abc272/f](https://atcoder.jp/contests/abc272/tasks/abc272_f)
- Problem Name: F - Two Strings
- difficulty: `4`
- tags: []
- tag_en: []
- id: `atcoder/abc272/f`
- logged_at: `2026-07-08`

## memo

I built the suffix array of $SSTT$.

At the suffix array positions, the range corresponding to the interval is obtained by considering the region before or after itself where the LCP is exactly $N$.
