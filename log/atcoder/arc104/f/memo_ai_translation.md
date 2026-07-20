> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F - Visibility Sequence

- Problem: [atcoder/arc104/f](https://atcoder.jp/contests/arc104/tasks/arc104_f)
- Problem Name: F - Visibility Sequence
- difficulty: `5`
- tags: `Cartesian_Tree` `タイブレイク` `区間dp`
- tag_en: `Cartesian Tree` `tiebreak` `interval DP`
- id: `atcoder/arc104/f`
- logged_at: `2026-07-03`

## memo

Roughly speaking, the question is: how many possible Cartesian Trees are there?

However, the tiebreak needs to be handled carefully. Suppose that equal values are regarded as larger when they are on the right side.

First, consider the decision problem: can a certain Cartesian Tree structure be generated from the sequence $H$?

Then this can be determined by a greedy approach that assigns the smallest possible values from bottom up.

So,

- dp[l][r][x]: the number of ways to make $[L,R)$ into a rooted tree with root value $x$

This gives an interval DP.
