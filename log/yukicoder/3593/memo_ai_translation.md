> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# No.3593 I Love Sudoku

- Problem: [yukicoder/3593](https://yukicoder.me/problems/no/3593)
- Problem Name: No.3593 I Love Sudoku
- difficulty: `8`
- tags: `線形代数` `構築` `群` `数独`
- tag_en: `linear algebra` `construction` `group` `sudoku`
- id: `yukicoder/3593`
- logged_at: `2026-07-17`

## memo

Prepare a $9$-element group $G$.

Consider the group algebra over $G$,

and let $a = \sum a_gX^g$, $b = \sum b_gX^g$.
First, as the convolution $c = \sum c_g X^g$, search for ones where $a$, $b$, and $c$ are each permutations.

If we regard these as matrices, then the row conditions and column conditions are automatically satisfied.

The block conditions are adjusted by applying suitable permutation matrices to these.

- $A'=PAQ$
- $B'=Q^{-1}BR$
- $C'=PCR$

In this way, we aim for the block conditions.

Taking

$$G = \mathbb{Z}/3\mathbb{Z}\times \mathbb{Z}/3\mathbb{Z}$$

worked well.

At first, I was thinking about something corresponding to $G = \mathbb{Z}/9\mathbb{Z}$ (without using group language), but I then organized it using group language and changed direction to this approach.
