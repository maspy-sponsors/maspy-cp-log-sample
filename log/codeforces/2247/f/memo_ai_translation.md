> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F. Paths on a Grid

- Problem: [codeforces/2247/f](https://codeforces.com/contest/2247/problem/F)
- Problem Name: F. Paths on a Grid
- difficulty: `5`
- tags: `dominator_tree` `ハッシュ`
- tag_en: `dominator_tree` `hash`
- id: `codeforces/2247/f`
- logged_at: `2026-07-19`

## memo

This is asking for an equivalence-class decomposition under the relation “if a path goes through $A$, then it also goes through $B$, and vice versa.”

If we build a dominator tree rooted at $s$ and a dominator tree rooted at $t$, then this is equivalent to both of the following holding:

- $u$ is an ancestor of $v$ in tree $T_A$
- $v$ is an ancestor of $u$ in tree $T_B$

After that, we just need to decompose into equivalence classes under this relation.

- In $T_A$, there is a dominator relation $a\to b\to c$ from the ancestor side
- $a$ and $c$ belong to the same equivalence class

Assume this. For a path $P$,

- $c\in P\implies b\in P\implies a\in P$
- $a\in P\iff c\in P$

so in this case we can show $a\in P\iff b\in P$ and $b\in P\iff c\in P$.

Then, in the end, the equivalence relation between $a$ and $c$ is generated from the relation between $a$ and $b$ and the relation between $b$ and $c$.

Therefore, the equivalence relation can be generated from direct parent-child relations in $T_A$.

----

Alternative solution information

Attach a weight $a_v$ to each vertex, and define the weight of a path as the product of the weights of the cells it passes through.

For a given vertex, consider the sum of the weights of paths that pass through it.

If we regard $a_v$ as indeterminates, vertices with the same sum are in the same connected component.

This can be done by making $a_v$ random.
