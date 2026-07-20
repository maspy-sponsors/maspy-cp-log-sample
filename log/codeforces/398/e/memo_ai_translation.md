> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. Sorting Permutations

- Problem: [codeforces/398/e](https://codeforces.com/contest/398/problem/E)
- Problem Name: E. Sorting Permutations
- difficulty: `7`
- tags: `マッチングによるスワップ` `交互パス`
- tag_en: `swap by matching` `alternating path`
- id: `codeforces/398/e`
- logged_at: `2026-07-08`

## memo

The `k` given in the second sentence of the statement and the `k` given later in the statement and in Input are unrelated!!!!

We consider what patterns can be made with two rounds of swapping by matching (in conclusion, it turns out that every permutation can be made). If we draw edges of color 1 for the pairs swapped in the first round and edges of color 2 for the pairs swapped in the second round, then each connected component is either an "alternating path" or an "alternating cycle". It can be seen that one cycle is created from an alternating path, and two cycles of half the length are created from an alternating cycle.

Conversely, to make a given permutation in two rounds, it is enough to choose an alternating path corresponding to each cycle, or choose an alternating cycle that can create two cycles of the same length together.

If we do a DP like `dp[cycle len][cycle cnt]` (with $O(N\log N)$ states), then from the cycle decomposition of a permutation we can compute the number of such ways.

Whether a permutation can be made in 0 or 1 round can also be determined only from information in the cycle decomposition of the permutation.

After that, it is enough to handle the `k` blanks. This can be handled by exhaustive search over Bell$(k)$.
