> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. Kevin and And

- Problem: [codeforces/2061/e](https://codeforces.com/contest/2061/problem/E)
- Problem Name: E. Kevin and And
- difficulty: `4`
- tags: `min_plus_convolution` `凸性の証明`
- tag_en: `min-plus convolution` `proof of convexity`
- id: `codeforces/2061/e`
- logged_at: `2026-07-19`

## memo

For each $i$, precompute the optimal value for each number of operations. This can be done in $O(2^M)$ time.

The key point is that this becomes a lower convex function. The proof feels quite unusual. The final solution is just to perform min-plus convolution on many lower convex functions.

Now we prove convexity. Fix $a \in A$.

- For a subset $S$ of $B$, let $f(S)$ be the value obtained by ANDing all elements of $S$.
- Let $F(k)$ be the minimum value of $f(S)$ over all $S$ with $|S|=k$.
- Show that $2F(k+1)\leq F(k)+F(k+2)$.
- If we set $f(S)=F(k)$ and $f(T)=F(k+2)$, it suffices to show $2F(k+1)\leq f(S)+f(T)$.

It is enough to assume $f(S)>f(T)$, and take the highest bit among those on which $f(S)$ and $f(T)$ differ. If $b\in B$ is the element causing this difference, then we can show

$$
f(S)+f(T)\geq f(S\cup \{b\})+f(S\cup \{b\})
$$
