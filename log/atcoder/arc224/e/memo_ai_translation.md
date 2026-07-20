> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - ABC|AB|A

- Problem: [atcoder/arc224/e](https://atcoder.jp/contests/arc224/tasks/arc224_e)
- Problem Name: E - ABC|AB|A
- difficulty: `3`
- tags: []
- tag_en: []
- id: `atcoder/arc224/e`
- logged_at: `2026-07-12`

## memo

A greedy approach of deleting `ABC` if it exists, and otherwise deleting `AB` if it exists, is sufficient.

It also seems possible to delete one character at a time from the front more simply, but it becomes a little tricky because even after seeing `AB`, you still do not know what the next character is, and so on.

If we reverse the string, then when we scan from the front and encounter `A`, it becomes easy to process one character at a time by deleting the longest of `CBA`, `BA`, and `A`.
