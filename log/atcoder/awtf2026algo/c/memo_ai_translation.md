> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# C - Count by Descents

- Problem: [atcoder/awtf2026algo/c](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_c)
- Problem Name: C - Count by Descents
- difficulty: `9`
- tags: `Eulerian_Polynomial` `descent`
- tag_en: `Eulerian Polynomial` `descent`
- id: `atcoder/awtf2026algo/c`
- logged_at: `2026-07-10`

## memo

Counting permutations by the number of descents is a famous problem, and the conclusion is the Eulerian Polynomial. First, we should properly understand a good way to derive it.

We divide the sequence into $k$ intervals and double-count the number of ways such that "the sequence is increasing within each interval." At this time, empty intervals are also allowed.

First, one way to count is to decide the interval number assigned to each element, which gives $k^n$ ways.

Next, fix a permutation. At descent positions, we must surely cut. Consider inserting block boundaries at the $n+1$ positions between elements; then the state becomes: "assign at least $1$ to $d$ of them and at least $0$ to the others, with the total being $k-1$."

From this, the famous formula

$$
(1-x)^{-(n+1)} \sum_{i=0}^{\infty}i^nx^i
$$

for the Eulerian Polynomial emerges.

----

We extend this to weights $\prod (x_i+i)$. By using 0-based indexing, this corresponds to:

- Arrange the elements.
- Choose one element as the root and give it weight $x_i$.
- For the other elements, choose a parent with a smaller index.

Following the derivation of the Eulerian Polynomial, we consider embedding such a forest structure into $K$ blocks. Then, for each connected component, once the vertex set and root are fixed, the number of ways to embed becomes a simple formula, though not as simple as $k^n$. More specifically, it can be expressed using the block number containing the root, the number of elements smaller than the root, and the number of elements larger than the root.

At this point, it becomes polynomial-time. Process the elements in ascending order, and perform transitions like:

- For elements smaller than the root, leave them pending as small elements.
- Use it as the root of a new connected component, choose how many to use as small and large, and also decide which of the previously unused small elements to assign; add large acceptance capacity.
- Put it into one of the existing large acceptance slots and use it as a large element.

Finally, speed this up using 2D convolution.
