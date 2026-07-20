> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# J - 道路ネットワークの整備

- Problem: [atcoder/awc0100/j](https://atcoder.jp/contests/awc0100/tasks/awc0100_j)
- Problem Name: J - 道路ネットワークの整備
- difficulty: `4`
- tags: `HLD` `パスクエリ`
- tag_en: `HLD` `path query`
- id: `atcoder/awc0100/j`
- logged_at: `2026-06-28`

## memo

There are two kinds of queries: adding $1$ to the edges on a path, and a min query. For example, it is enough to process path queries with HLD.

https://info.atcoder.jp/entry/algorithm_lectures/heavy_light_decomposition

In any case, since it is split into an addition phase and a path-query phase, the choice of solution is a bit broader.

For example, if implementing this problem from scratch just for this task, doubling (binary lifting) might be easier.
