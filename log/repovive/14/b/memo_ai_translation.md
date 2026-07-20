> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# 14B. Queue Fronts

- Problem: [repovive/14/b](https://repovive.com/contests/14/problems/B)
- Problem Name: 14B. Queue Fronts
- difficulty: `3`
- tags: `連長圧縮` `貪欲`
- tag_en: `run-length compression` `greedy`
- id: `repovive/14/b`
- logged_at: `2026-06-30`

## memo

In the end, the form is to merge everything together first, and then split it into $M$ pieces.

It is a form where we take at most $M$ components after run-length compression.

Roughly speaking, those can be chosen freely, but the very first component is forced to be used.
