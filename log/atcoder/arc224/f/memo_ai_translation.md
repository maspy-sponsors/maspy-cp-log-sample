> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F - AND/OR

- Problem: [atcoder/arc224/f](https://atcoder.jp/contests/arc224/tasks/arc224_f)
- Problem Name: F - AND/OR
- difficulty: `5`
- tags: `二項係数累積和`
- tag_en: `binomial coefficient prefix sums`
- id: `atcoder/arc224/f`
- logged_at: `2026-07-12`

## memo

If we decide to find the maximum value by binary search, then in the end we only need to solve the following.

- Given a target bit mask $X$,
- determine whether there exists a sequence of operations such that the bits of $X$ are at least $1$, or count such sequences.

We decide the operations from the back.

When $X \subset A$:

- Use OR. Victory is guaranteed. The operations before that may be arbitrary.
- Use ANS. The winning condition does not change.

Otherwise:

- We have no choice but to use OR. The winning condition changes to $X \setminus A$.

More precisely, since there is a condition on the number of operations, when victory is guaranteed, we judge based on how many ORs have been used so far.

The counting is the same. Since it is not exactly $K$ times but at most $K$ times, we need binomial coefficient prefix sums.
