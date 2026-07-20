> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# D2. Construct an Array (Hard Version)

- Problem: [codeforces/2245/d2](https://codeforces.com/contest/2245/problem/D2)
- Problem Name: D2. Construct an Array (Hard Version)
- difficulty: `7`
- tags: `構築` `potential` `頂点倍加`
- tag_en: `construction` `potential` `vertex doubling`
- id: `codeforces/2245/d2`
- logged_at: `2026-07-17`

## memo

Well, it is difficult.

First, as a necessary condition, if there is an alternating cycle of the form `+-+-+-`, then it is impossible.
This can be described as a directed cycle in the following graph.

- `+` edge: $2i\to 2j+1$.
- `-` edge: $2i+1\to 2j$.

Conversely, if these do not exist, then it is a DAG.
Since it is a DAG, there are no negative cycles, so we can assign edge weights and define potentials.

- For `+` edges: $p[2j+1] \leq p[2i], p[2i+1]\leq p[2j]$
- For `-` edges: $p[2j] \leq p[2i+1]-1, p[2i]\leq p[2j+1]-1$

If we assign potentials so that these hold and set $a[i]=p[2i]-p[2i+1]$, then the desired construction is achieved.

This is pretty close to ABC461G?
