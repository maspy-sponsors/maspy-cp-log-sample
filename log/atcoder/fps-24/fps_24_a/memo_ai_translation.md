> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# A - お菓子

- Problem: [atcoder/fps-24/fps_24_a](https://atcoder.jp/contests/fps-24/tasks/fps_24_a)
- Problem Name: A - お菓子
- difficulty: `3`
- tags: `疎なFPS`
- tag_en: `sparse FPS`
- id: `atcoder/fps-24/fps_24_a`
- logged_at: `2026-07-02`

## memo

It can be formulated as $[x^N](x+x^3+x^4+x^6)^D$.

Since this is sparse FPS exponentiation, it can be solved in $O(N)$ time.
