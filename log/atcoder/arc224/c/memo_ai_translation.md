> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C - Ascending Labels

- Problem: [atcoder/arc224/c](https://atcoder.jp/contests/arc224/tasks/arc224_c)
- Problem Name: C - Ascending Labels
- difficulty: `2`
- tags: `DFS木`
- tag_en: `DFS tree`
- id: `atcoder/arc224/c`
- logged_at: `2026-07-12`

## memo

The DFS tree satisfies the condition. This is because there are only tree edges or back edges (in this case, since there are no multiple edges, they go to ancestors at depth $2$ or more).

At first I made a BFS tree, but I overlooked the “exactly $1$” part.
