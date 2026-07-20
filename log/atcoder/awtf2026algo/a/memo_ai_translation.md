> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# A - Min Cut of Graph of Min Weight

- Problem: [atcoder/awtf2026algo/a](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_a)
- Problem Name: A - Min Cut of Graph of Min Weight
- difficulty: `6`
- tags: `最小カット` `マージ過程の木`
- tag_en: `minimum cut` `merge tree`
- id: `atcoder/awtf2026algo/a`
- logged_at: `2026-07-10`

## memo

If we consider connecting edges in increasing order of weight, then the capacity is the edge weight used at the moment when the two vertices become part of the same connected component.

So, if we build a merge tree and assign weights to internal nodes, then the edge capacity is the vertex weight of the LCA. Also, as long as the merge tree itself is the same, the answer does not change, so we can completely forget the original tree below. We will think only about this tree.

In fact, when finding the cut for $f(i,j)$, it turns out that it is enough to consider only cuts corresponding to some edge in this merge tree.
I confirmed this experimentally. As a proof, for a subtree not contained in the $i,j$ path, it is immediately clear that we may make it all one color, and then from there it can be shown with an appropriate exchange argument.

After that, if we compute all values corresponding to the edges to be cut, $f(i,j)$ can be described as the minimum edge weight on the path.

Depending on the implementation, using i128 makes overflow and similar issues less likely.
