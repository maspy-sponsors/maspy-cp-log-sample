> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B - 整数の組

- Problem: [atcoder/fps-24/fps_24_b](https://atcoder.jp/contests/fps-24/tasks/fps_24_b)
- Problem Name: B - 整数の組
- difficulty: `3`
- tags: `C-recursive`
- tag_en: `C-recursive`
- id: `atcoder/fps-24/fps_24_b`
- logged_at: `2026-07-02`

## memo

It can be formulated as $[x^N](1+x)\cdot (1+x^2)\cdot \frac{1}{1-x^2}\cdot \frac{1}{1-x^3}$.

This is a problem of finding the coefficient of a rational function (a problem of finding the $K$-th term of a linear recurrence), and can be solved by the Bostan-Mori method, etc.
$O(\log N)$ time.
