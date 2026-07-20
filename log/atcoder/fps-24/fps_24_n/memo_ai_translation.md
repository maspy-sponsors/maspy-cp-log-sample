> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# N - 硬貨 2

- Problem: [atcoder/fps-24/fps_24_n](https://atcoder.jp/contests/fps-24/tasks/fps_24_n)
- Problem Name: N - 硬貨 2
- difficulty: `4`
- tags: `FPS_log`
- tag_en: `FPS log`
- id: `atcoder/fps-24/fps_24_n`
- logged_at: `2026-07-02`

## memo

The answer can be formulated as follows:

$$[x^N] \prod_i (1+x^i+x^{2i}+\cdots+x^{iA_i})$$

If we rewrite this in the form like $\frac{1-x^{i(A+1)}}{1-x^A}$, then it suffices to multiply $O(N)$ formal power series of the form $(1-x^a)^{\pm 1}$.

Since $\log(1-x^A)$ has only about $O(N/A)$ terms up to degree $N$, the problem can be solved in $O(N\log N)$ time by computing the logarithm and then feeding it into the exponential.
