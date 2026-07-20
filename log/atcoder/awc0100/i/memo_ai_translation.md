> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# I - 円陣パスゲーム

- Problem: [atcoder/awc0100/i](https://atcoder.jp/contests/awc0100/tasks/awc0100_i)
- Problem Name: I - 円陣パスゲーム
- difficulty: `3`
- tags: `Fenwick_Tree` `セグメント木`
- tag_en: `Fenwick Tree` `Segment Tree`
- id: `atcoder/awc0100/i`
- logged_at: `2026-06-28`

## memo

Consider an array made up of only the surviving people.

- Delete $x$ from the array
- Assuming the array has length $n$, move from index $i$ to the $(i+D) \bmod n$-th element

If we can do something like this, then it is good. However, since deleting from the array and closing the gaps cannot be done quickly, we use some suitable data structure.

By keeping a $01$ sequence indicating whether the $i$-th element exists or not, we can do this by binary searching for the boundary where the prefix sum becomes $k$ or $k+1$.

Typically, use a Fenwick Tree or a segment tree.
