> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F2. Kevin and Binary String (Hard Version)

- Problem: [codeforces/2061/f2](https://codeforces.com/contest/2061/problem/F2)
- Problem Name: F2. Kevin and Binary String (Hard Version)
- difficulty: `6`
- tags: []
- tag_en: []
- id: `codeforces/2061/f2`
- logged_at: `2026-07-19`

## memo

Implement with care.

We do DP that chooses the index of the block to be fixed without performing any operations.

Using the block index as the key, the transition looks like

$$
dp[j] \leftarrow dp[i] + (j-i-1)/2
$$

The transition target $(i,j)$ satisfies the following conditions:

- $i\not\equiv j\pmod{2}$
- Performing operations on the block segment in $[i+1,j)$ matches $t$ (there is no block that does not move)

Then we compute this appropriately.

This is the part I did not notice: doing operations so that there is no block that does not move means that, for example, for 001100110011, the result is 111111000000. This can be shown by considering the number of blocks moved in one operation, or the decrease in the number of connected components, etc.

In the end, for some part to match $t$, if $t$ has no ? then the state is something like 0000011111 or 111100000. Because of this, the structure of $t$ is quite restricted.

Suppose blocks $i,j$ are $0$ and $1$, respectively. If we case-split into

- neither $x$ nor $y$ exists (all are ?)
- $x$ exists but $y$ does not
- $y$ exists but $x$ does not
- both $x$ and $y$ exist

then we can see that, when $i$ is fixed, the destination $j$ of the transition, or when $j$ is fixed, the source $i$ of the transition, becomes an interval (with parity fixed). So after that, we carefully process these transitions with a segment tree or a dual segment tree.
