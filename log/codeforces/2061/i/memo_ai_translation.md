> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# I. Kevin and Nivek

- Problem: [codeforces/2061/i](https://codeforces.com/contest/2061/problem/I)
- Problem Name: I. Kevin and Nivek
- difficulty: `8`
- tags: `2次元dpの分割統治高速化`
- tag_en: `divide and conquer optimization for 2D dp`
- id: `codeforces/2061/i`
- logged_at: `2026-07-19`

## memo

Let $j$ be the number of wins at the point where $i$ rounds have been processed; then a DP table of the form `dp[i][j]` can be considered.

We speed up the transitions from `dp[0]` to `dp[N]` using divide and conquer.

Design a recursive function that performs the transition from `dp[L][a,b)` to `dp[R]`.

In this setting, transitions from intervals near the ends, such as $[a,c), [d,b)$, can be handled together by min-plus convolution.

Transitions from the middle $[c,d)$ part are decomposed into $L\to M\to R$ and transitioned.
