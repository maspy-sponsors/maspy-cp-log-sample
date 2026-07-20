> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G. NPC Challenge

- Problem: [codeforces/2245/g](https://codeforces.com/contest/2245/problem/G)
- Problem Name: G. NPC Challenge
- difficulty: `7`
- tags: `インタラクティブ`
- tag_en: `interactive`
- id: `codeforces/2245/g`
- logged_at: `2026-07-17`

## memo

**The query cost evaluation is unclear!!**

In some arbitrary vertex order, query all vertices. Then an independent set and a forest are obtained.
Repeat this.

This partitions the vertices into independent sets $V_1, V_2, \ldots$.

After that, identify the edges between $V_i$ and $V_j$.
For edges between a bipartite graph $(X, Y)$, I did it with binary search-like splitting of $X$ into $X_1, X_2$.

- Insert shuffle, etc. everywhere
- Tested on random trees, paths, stars, and complete binary trees, and it seemed to work

→ AC???

I do understand that the cost should be around $O(N\log N)$, but I understand nothing else.


The initially obtained maximal independent set:
A vertex of degree $d$ is selected with probability $1/(d+1)$.

Probably, the expected size is around $[n/3, n/2]$. (path, star)

From here, it became possible to think that various things would be $O(N\log N)$.
