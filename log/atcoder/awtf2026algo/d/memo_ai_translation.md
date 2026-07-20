> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D - Adj Swap Lex Max

- Problem: [atcoder/awtf2026algo/d](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_d)
- Problem Name: D - Adj Swap Lex Max
- difficulty: `9`
- tags: `隣接スワップ`
- tag_en: `adjacent swap`
- id: `atcoder/awtf2026algo/d`
- logged_at: `2026-07-11`

## memo

## Decision problem

First, consider the decision problem of whether an exact $P\to Q$ transformation is possible. Removing any extra lcp, assume that $P[0] < Q[0]$.
We call a pair a crossing pair if the inversion relation between $P$ and $Q$ disagrees for that pair.

Consider the reverse operation. Writing $Q$ as $Q_{init}$, let $A$ be the $Q$ during the operation process.
For decreasing $k$, we solve: "if we consider performing operations only on the indices $k,k+1,\ldots$, find the set of possible values of $A[k]$."

Once we can reach $A[k] < Q[k]$, then from there on, as long as we preserve only the constraints of crossing pairs, we can operate freely on positions from $k+1$ onward. From this, the set of possible values for $A[k]$ is either

- only $Q[k]$, or
- all values that are at most $Q[k]$ and can be first in a topological order of the crossing-pair constraints

one of these two.

Using this, the decision problem can be solved from the back by considering the reverse operation.

## Relation to the official editorial

If this is organized sufficiently, it becomes the decision condition in the official editorial.
This corresponds to $Z$, the last possible (that is, smallest) index where $A[k] < Q[k]$ can hold.

## Lexicographic maximization

Based on this, it seems we can first do lexicographic maximization in polynomial time.

I reached this point on my own, and thought the rest was just a matter of time, but somehow this part was hard.
If done naively, I think it would become something like finding "the maximum among those at most $c$ that are still okay to add," but I couldn't fully sort it out.

In the end, while staring at the official editorial over and over, I solved it by carefully checking each condition and proof one by one. In the end, maybe because I never really got used to the setting or the decision conditions, I could follow the proof but never quite felt that it was obvious; it feels like a pretty clever solution.
