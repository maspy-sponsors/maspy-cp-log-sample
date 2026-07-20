> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C - Reverse Permutation

- Problem: [atcoder/abc465/c](https://atcoder.jp/contests/abc465/tasks/abc465_c)
- Problem Name: C - Reverse Permutation
- difficulty: `3`
- tags: `deque` `シミュレーション`
- tag_en: `deque` `simulation`
- id: `atcoder/abc465/c`
- logged_at: `2026-07-04`

## memo

It becomes easy if we restate it as follows:

- push back $i$.
- Depending on the character, reverse or do not reverse.

Instead of reversing the whole structure, keep only a flag indicating whether it is reversed, and treat insertions as adding to the front or the back.
For example, using a deque lets you naturally simulate this process.
