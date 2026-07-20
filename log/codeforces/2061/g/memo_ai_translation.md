> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# G. Kevin and Teams

- Problem: [codeforces/2061/g](https://codeforces.com/contest/2061/problem/G)
- Problem Name: G. Kevin and Teams
- difficulty: `5`
- tags: `インタラクティブ` `帰納的構成`
- tag_en: `interactive` `inductive construction`
- id: `codeforces/2061/g`
- logged_at: `2026-07-19`

## memo

This is a problem of finding a matching of size about $N/3$ in $G$ or in its complement graph.

The key point is that it is enough to take one point from each 3 vertices.

So, once we find

- 3 points $a,b,c$
- color(a,b) != color(b,c)

we can remove these 3 points, solve the remaining problem, and then choose any color at the end. Thinking in terms of being happy once such a configuration is found leads to a relatively simple construction.

We build a monochromatic path while appending unexplored vertices to the end. When it stops being monochromatic, we pop the last 3 vertices and reserve them for the above process. In the end, we can split the vertices into a monochromatic path and groups of 3, and from there construct a monochromatic matching.
