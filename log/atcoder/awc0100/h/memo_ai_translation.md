> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# H - 都市の巡回調査

- Problem: [atcoder/awc0100/h](https://atcoder.jp/contests/awc0100/tasks/awc0100_h)
- Problem Name: H - 都市の巡回調査
- difficulty: `2`
- tags: `シミュレーション`
- tag_en: `simulation`
- id: `atcoder/awc0100/h`
- logged_at: `2026-06-28`

## memo

Simulate exactly as described in the problem statement.

To find the "most important unvisited city," it is enough to manage the destinations of all cities and a `visited` array.

Since each search from the same city is performed only once, there should be no need to worry about computational complexity with a standard implementation.

As for complexity, some care is needed when deciding the starting city, and this can be handled with a priority queue or a sorted array, etc.
