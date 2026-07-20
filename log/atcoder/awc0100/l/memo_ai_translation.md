> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# L - スケジュール調整

- Problem: [atcoder/awc0100/l](https://atcoder.jp/contests/awc0100/tasks/awc0100_l)
- Problem Name: L - スケジュール調整
- difficulty: `4`
- tags: `two_sat` `reachability` `transitive_closure`
- tag_en: `two sat` `reachability` `transitive closure`
- id: `atcoder/awc0100/l`
- logged_at: `2026-06-28`

## memo

In other words, this becomes: “Find the lexicographically smallest solution of the two sat problem.”

For two sat, duplicate each vertex $v$ into $v_{0}, v_{1}$, build a directed graph with $2N$ vertices, and if no pair of $v_1, v_2$ belongs to the same strongly connected component, then the problem has a solution.

By binary search, we can find the largest $K$ for which a solution exists.

After that, decide the variables one character at a time. For example, “deciding $v$ to be $0$” corresponds to adding an edge equivalent to $v_1 \to v_0$.

What we need to do is:

“Try to add one edge. If reachability of the form $w_0 \to w_1$ and $w_1 \to w_0$ seems likely to arise, then fail. If trying to make it $0$ fails, then add $1$.”

We can do this. Maintain a matrix representing reachability at each point in time (transitive closure), and for edge additions, judgment and updates can be performed with suitable bitset processing.

I misunderstood the constraints, but it seems the constraints were such that we could redo two sat from scratch every time an edge is added.
