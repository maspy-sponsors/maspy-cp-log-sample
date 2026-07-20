> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B. Painting The Wall

- Problem: [codeforces/398/b](https://codeforces.com/contest/398/problem/B)
- Problem Name: B. Painting The Wall
- difficulty: `3`
- tags: []
- tag_en: []
- id: `codeforces/398/b`
- logged_at: `2026-07-08`

## memo

The state at some point can be represented by the number of rows and the number of columns that have at least one painted cell. Then this becomes a DAG with $O(N^2)$ vertices, and the transition probabilities are also easy to determine, so the problem reduces to finding the expected number of steps until reaching the goal, which can be solved with a suitable DP.
