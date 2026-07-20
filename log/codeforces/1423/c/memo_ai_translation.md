> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C. Dušan's Railway

- Problem: [codeforces/1423/c](https://codeforces.com/contest/1423/problem/C)
- Problem Name: C. Dušan's Railway
- difficulty: `7`
- tags: `SQRT_tree`
- tag_en: `SQRT tree`
- id: `codeforces/1423/c`
- logged_at: `2026-07-14`

## memo

It has to be solved with $k=3$.

If we consider the case where the tree is a path, then this can be solved with a structure like a SQRT tree. It is well known as a static monoid interval product query. When values of a monoid are written on the edges, it enables interval queries between two points as a monoid product of at most 3 elements, with preprocessing in $O(N\log\log N)$ time and space, and each query in $O(1)$ time.

- Square-decompose the sequence.
- Prepare shortcuts for every pair of block-boundary points.
- Prepare shortcuts from block boundaries to all points inside that block, to the left and right.
- With this, everything is solved except for the case where the interval query is completely contained in one block.
- The case where the interval query is completely contained in one block is handled recursively.

In this way, for each $k$, the number of shortcuts at the $k$-th step of the recursion is $O(N)$, and overall it becomes $O(N\log\log N)$. This is the mechanism of a SQRT tree.

This is for a path graph, but the same thing just needs to be realized on a tree.

“Square-decompose the tree.” There are several variants of tree square decomposition (see https://noshi91.hatenablog.com/entry/2019/12/07/140433), but it is enough to use a form that partitions the edge set.

Do a DFS and partition bottom-up. If you decide a component once the number of edges reaches $\sqrt{N}$ or more, you can partition it into components whose size (number of edges) is in $[\sqrt{N}, 2\sqrt{N}]$.

When the root of component $S$ is $r$,

- Add shortcuts from all vertices in $S$ to $r$
- Add shortcuts from $r$ to all points inside the component that have an edge in the parent direction
- Add shortcuts for all pairs of “roots of components”

With this, the number of shortcuts created at the $k$-th stage of the recursion becomes $O(N)$, and since the recursion depth is $\log\log N$ steps, the total number of shortcuts is bounded by $O(N\log\log N)$.
