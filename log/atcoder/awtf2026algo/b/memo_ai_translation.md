> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# B - Window Records

- Problem: [atcoder/awtf2026algo/b](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_b)
- Problem Name: B - Window Records
- difficulty: `7`
- tags: `判定問題解法でdp`
- tag_en: `DP by solving a decision problem`
- id: `atcoder/awtf2026algo/b`
- logged_at: `2026-07-10`

## memo

First, let us check how to compute $x$ from $p$.

Process the sequence from the back. This can be done as follows.

- Manage the sequence of records at each moment
- When adding $p_i$ to the front, remove records smaller than or equal to it from the prefix side
- If the last record being kept is outside the window of size $N$, remove it
- Add $i$ to the front as a record

Given this behavior, next consider the decision problem for the sequence $x$.

For the same $x$, there may be multiple ways to move the record sequence that realize it. For this, there remains a $2$-choice freedom between the pop_front side and the pop_back side (the latter is at most one). In fact, it can be shown that, whenever possible, prioritizing the pop_back side is a greedy choice. The pop_front side can be done later at any desired timing, whereas pop_back forces that at some step, a record must remain exactly at that index position.

With this, if we prioritize the pop_back side, the decision problem can first be solved in $O(N)$ time. Since the state appearing here can be written with $polynomial(N)$ states, we can simply turn the solution to that decision problem into a DP as is.

Concretely, it is enough to use as the state the number of elements with index at most $N$, and the pair of counts of pop_front and pop_back performed from the part with index at least $N+1$.
