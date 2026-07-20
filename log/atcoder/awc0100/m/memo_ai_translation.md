> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# M - 秘密の数列と分岐するノート

- Problem: [atcoder/awc0100/m](https://atcoder.jp/contests/awc0100/tasks/awc0100_m)
- Problem Name: M - 秘密の数列と分岐するノート
- difficulty: `5`
- tags: `Rollback_UnionFind` `ポテンシャル付きUnionFind`
- tag_en: `Rollback_UnionFind` `Weighted UnionFind`
- id: `atcoder/awc0100/m`
- logged_at: `2026-06-28`

## memo

As stated by “the versions branch out into a tree,” we build exactly such a tree, and then compute the answer for each version while performing a DFS traversal of the tree.

Then, it is enough to be able to do “adding conditions (judging whether they can be added)” and “rollback.”

In general, removing conditions added long ago in an arbitrary order is difficult, but rollback is easy.
We just need to remember all array updates performed in the meantime, and restore them one by one.

For this problem, we handle the addition of conditions and rollback by using a potentialized UnionFind.
