> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# H2. Kevin and Stones (Hard Version)

- Problem: [codeforces/2061/h2](https://codeforces.com/contest/2061/problem/H2)
- Problem Name: H2. Kevin and Stones (Hard Version)
- difficulty: `9`
- tags: `マッチング` `木上の輸送`
- tag_en: `matching` `transport on trees`
- id: `codeforces/2061/h2`
- logged_at: `2026-07-19`

## memo

Amazing. I looked at almost all of the editorial.

First, handle the case that finishes in $0$ moves as a special case.

Solve it separately for each time parity. Double the vertices according to the time parity. The following is needed:

- For each connected component, the number of stones is invariant between the initial state and the final state.
- The first $1$ move and the last $1$ move can be moved around (existence of a bipartite matching that saturates one side)

These are sufficient conditions, and they give the solution for H1.

----

Now consider the solution for H2.

Take a spanning tree that contains the matching edges corresponding to $S, T$. A cycle may be formed as the union of matchings, but in that case we can rebuild the matching.

Eventually, we get the following situation:

- There is a spanning tree. Among it, there are matchings $S, T$.
- At time $i$, stones come to the vertices whose depth parity is $i$.
- The initial state is $S$, and the final state is $T$. Move them inside the tree.

I think even from here, it is difficult to move them while avoiding collisions in $2N$ moves.

Focus on the deepest one among the matching $S, T$.

Assume that $T$ is deep. Move it from the nearest starting edge $S$ toward $T$.

At this time, make it move to $T$ as quickly as possible (and then keep it oscillating back and forth at $T$). Also, make the other stones move using only the range from time $2$ onward. Then, from the way $S, T$ are chosen, one can prove that they will not collide with other stones. If it could collide with this stone after waiting, then it would mean that it could reach $T$ earlier.
