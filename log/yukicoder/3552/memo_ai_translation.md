> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# No.3552 Triangular Coloring

- Problem: [yukicoder/3552](https://yukicoder.me/problems/no/3552)
- Problem Name: No.3552 Triangular Coloring
- difficulty: `4`
- tags: `点彩色`
- tag_en: `vertex coloring`
- id: `yukicoder/3552`
- logged_at: `2026-07-14`

## memo

The point that was “added” last has degree at most $3$. In the end, by repeatedly deleting vertices of degree at most $3$, the graph can be reduced to at most $3$ vertices.

The graph before deletion can be 4-colored using a 4-coloring of the graph after deletion.
