> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E - Even Rows

- Problem: [atcoder/awtf2026algo/e](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_e)
- Problem Name: E - Even Rows
- difficulty: `10`
- tags: `+-1列の累積和` `マッチング`
- tag_en: `+-1 column prefix sums` `matching`
- id: `atcoder/awtf2026algo/e`
- logged_at: `2026-07-11`

## memo

It's insanely hard.

Writing a careful explanation here is also hard, so I'll skip it.
I threw it into maroon, and it had them add some explanations to the original, so I figured that contributed to everyone's understanding.

Just the big picture.

First, when $M$ is even, it's easy: enumerate odd rows and process appropriately between adjacent pairs. This is often described by a cost like $j-i$, but here we can discover that there is an exceptional pattern (a bad pair).


Next, assume $M$ is odd. First, the goal is to solve the following.

- There is a nonnegative integer sequence such that all values are at most $M$.
- For adjacent $2$ terms, we can perform $(+1,-1)$ and $(-1,+1)$ operations, with the constraint that values must remain between $0$ and $M$ inclusive.
- Solve the cost to make all elements even.

Incidentally, even this alone is probably harder than a typical red problem.

If we examine the structure of this solution, a structure appears where we draw a polyline of the cumulative sum of $\pm 1$ and match equal heights.

On top of that, the bad pair structure also comes into play. In the solution, I struggled to work out the logic for the part that says, “It is enough to first minimize only the matching cost, and then minimize the bad pair cost on top of that.”


It took about three full days just to work out the proof details and implementation from the open explanation, and my implementation is 700 lines in `main.cpp` (though this includes various test implementations left over, and multiple re-implementations of the same thing). If you're going to tackle it, good luck.
