> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# J - スゴロク

- Problem: [atcoder/fps-24/fps_24_j](https://atcoder.jp/contests/fps-24/tasks/fps_24_j)
- Problem Name: J - スゴロク
- difficulty: `5`
- tags: `分割統治dp`
- tag_en: `divide and conquer dp`
- id: `atcoder/fps-24/fps_24_j`
- logged_at: `2026-07-02`

## memo

The goal is to obtain a dp table of the probability $\dp[i]$ of reaching $i$.

If we forbid transitions from NG cells and compute the total sum of dp values at NG cells, then the failure probability can be calculated.

There is some freedom in the computation order of the dp transitions, and it is sufficient to process them in an order satisfying the following:

- For all $i,j$ with $i<j$, compute the transition $\dp[i]\to \dp[j]$.
- However, at the point when $\dp[i]$ is computed, all transitions leading to $i$ have already been computed.

We compute this by divide and conquer. Let dfs(L,R) be a function that performs all transitions satisfying $L\leq i<j<R$; when dfs(L,R) is called, it suffices to call, in order:

- dfs(L,M)
- all-pairs transitions from $[L,M)$ to $[M,R)$
- dfs(M,R)

Since the middle processing can be made into a convolution of sequences of size $O(R-L)$, the whole problem can be solved in $O(N\log^2N)$ time.
