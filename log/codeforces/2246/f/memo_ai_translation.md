> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F. Whoname and Unsorted Array

- Problem: [codeforces/2246/f](https://codeforces.com/contest/2246/problem/F)
- Problem Name: F. Whoname and Unsorted Array
- difficulty: `5`
- tags: `構築` `ソート手順構築`
- tag_en: `construction` `sorting-procedure-construction`
- id: `codeforces/2246/f`
- logged_at: `2026-07-13`

## memo

Strictly speaking, this is an unproven solution, but I think it is fine.

First, handle the necessary parity condition.

For example, when $N=9$, move it closer in the following way:

- 7........
- 67.......
- 567......
- 4567.....
- 34567....
- 234567...
- .234567..

And there is an important operation in this process and also in the final finishing step.

- A234567BC
- BA234567C
- B234567CA

By operating on the front or the last $N-1$ elements, we can rotate only the ends. The central region stays fixed; if you look closely, this is because the operation in the problem statement roughly cancels out between “move everything to the right together” and “move everything to the left together”.

In the end, do the following.

- Focus on the position of the next number to bring to the front. If it is not at the end, we can bring it to the front in 1 move.
- Otherwise, adjust near the front and back, and bring it to the front in 3 moves.

In the “final finishing step,” parity cannot be adjusted, so with a rough estimate, it becomes “success with probability 1/2”.

However, this is a deterministic algorithm, so “probability” is just a state of mind.

By first performing random operations up to $N$ times and then feeding the result into the above solution, I was able to get AC.
