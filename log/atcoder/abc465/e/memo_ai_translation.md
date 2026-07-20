> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - Digit Circus

- Problem: [atcoder/abc465/e](https://atcoder.jp/contests/abc465/tasks/abc465_e)
- Problem Name: E - Digit Circus
- difficulty: `3`
- tags: `桁dp` `実装`
- tag_en: `digit dp` `implementation`
- id: `atcoder/abc465/e`
- logged_at: `2026-07-04`

## memo

This is a somewhat troublesome implementation, but it is a basic digit DP.

Use DP with the states:

- whether it is divisible by `3`
- the set of digits that have appeared
