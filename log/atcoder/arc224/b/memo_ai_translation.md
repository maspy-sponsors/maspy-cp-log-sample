> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B - Adjacent Tiles

- Problem: [atcoder/arc224/b](https://atcoder.jp/contests/arc224/tasks/arc224_b)
- Problem Name: B - Adjacent Tiles
- difficulty: `3`
- tags: `bounding_box`
- tag_en: `bounding box`
- id: `atcoder/arc224/b`
- logged_at: `2026-07-12`

## memo

It seems a little difficult if the proof is included too.

Let the bounding box type be $(H,W)$, and fix it.

We can think of the score as follows.

- For each square, if there is also a square above it, you get 1 point.
- For each square, if there is also a square to the left, you get 1 point.

Then the obvious upper bound is $2N$ points. However,

- the leftmost square in each row
- the topmost square in each column

cannot earn that score, and from this, when $H,W$ are fixed, the upper bound becomes $N-H-W$.

If we tile it in a plausible way, equality can be achieved, and in the end the problem becomes the following form.

- Maximize $2N-H-W$.
- However, $H+W-1\leq N\leq HW$.

Ignoring $H+W-1\leq N$ is fine in the end.
