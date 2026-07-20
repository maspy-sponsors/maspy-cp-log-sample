> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D - X to Y

- Problem: [atcoder/abc465/d](https://atcoder.jp/contests/abc465/tasks/abc465_d)
- Problem Name: D - X to Y
- difficulty: `2`
- tags: `K進法`
- tag_en: `K-ary notation`
- id: `atcoder/abc465/d`
- logged_at: `2026-07-04`

## memo

Rephrase the operation in terms of strings in base-$K$ notation (however, treat $0$ as the empty string on purpose).

If we do not perform the operation of changing $0$ to $0$, then the operation becomes adding or deleting at the end of the string.

Compute how many characters can be kept among the strings (the lcp of the strings).
