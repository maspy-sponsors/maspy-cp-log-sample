> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D. Instant Messanger

- Problem: [codeforces/398/d](https://codeforces.com/contest/398/problem/D)
- Problem Name: D. Instant Messanger
- difficulty: `5`
- tags: `次数による向きづけ` `次数平方分割`
- tag_en: `degree-based orientation` `degree square decomposition`
- id: `codeforces/398/d`
- logged_at: `2026-07-08`

## memo

If each edge is oriented from the endpoint with smaller vertex degree to the one with larger degree, then the outdegree of each vertex is small. Keep the answers for incoming edges, and for outgoing edges, fetch them when the query comes.
