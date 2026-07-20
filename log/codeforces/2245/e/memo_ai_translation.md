> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. Tom and Jerry

- Problem: [codeforces/2245/e](https://codeforces.com/contest/2245/problem/E)
- Problem Name: E. Tom and Jerry
- difficulty: `7`
- tags: `ゲーム`
- tag_en: `game`
- id: `codeforces/2245/e`
- logged_at: `2026-07-17`

## memo

After the first move, the game is played on an arbitrary rooted tree chosen by the player.

So, what we need to think about is not the tree, but the rooted tree.

On a rooted tree, astonishingly, the winner is determined only by the degree of the root.

I conjectured and proved this without experiments, but maybe experimenting would have been faster.

- If the root is even, it loses.
- If the root is odd, it wins.
- Proof of losing: if the opponent keeps choosing the same root, the opponent will receive an odd turn.
- Proof of winning: if we take a path whose only odd endpoints are both ends, such as `(odd, even, even, even, odd)`, we can pass a losing state to the opponent. Such a path must always exist as a prefix of a path to a leaf.

What we ultimately need to count is the strategy on the unrooted tree, but this can also be done by counting paths of the `(odd, even, even, even, odd)` type.
