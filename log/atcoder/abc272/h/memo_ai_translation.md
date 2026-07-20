> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# Ex - Flipping Coins 2

- Problem: [atcoder/abc272/h](https://atcoder.jp/contests/abc272/tasks/abc272_h)
- Problem Name: Ex - Flipping Coins 2
- difficulty: `7`
- tags: `固有関数` `rook_polynomial` `newton_basis` `下降べき`
- tag_en: `eigenfunction` `rook polynomial` `Newton basis` `falling factorial`
- id: `atcoder/abc272/h`
- logged_at: `2026-07-08`

## memo

I explained this in algorithm lectures.

At the time of the contest, I could not interpret the mysterious variable transformation in the official editorial well enough (for some reason, considering multiplication by $e^x$ makes things look nice),
but now I understand it as follows.

https://info.atcoder.jp/entry/algorithm_lectures/eigenfunction

----

First of all, this can be understood as a famous rook polynomial problem.

The application of the inclusion-exclusion principle is the problem of placing $k$ rooks on a Young diagram so that they do not interfere with each other, for each $k$.

Let $r_k$ be the number of ways to place $k$ rooks; then $\sum r_kx^k$ is called the rook polynomial of this Young diagram.

If the number of columns is sorted in ascending order as $A_i$, then by adding $x$ extra columns to each row and counting the number of ways to "place rooks in every row", we get the identity

$\prod_i (x + A_i - i) = \sum r_i (x)_i$

Here, $(x)_i$ is the falling factorial. Therefore, to find $r_i$, it suffices to convert the left-hand side to the Newton basis.

Also, the method in the editorial can be interpreted as using the following relationship between falling factorials and EGF.

- Let $f(x) = \sum_{i=0}^n a_i (x)_i$.
- Let $g(x) = \sum_{i=0}^n a_i x ^ i$.
- Then $e^xg(x) = \sum_{i=0}^{\infty} \frac{f(i)}{i!}x^i$

In other words, $f(x)$ is given and we want to find $g(x)$, and this is done by evaluating $f$ at multiple points to obtain $e^xg(x)$, from which $g(x)$ is found.
