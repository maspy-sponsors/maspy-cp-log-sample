> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# X - 関数的平方根

- Problem: [atcoder/fps-24/fps_24_x](https://atcoder.jp/contests/fps-24/tasks/fps_24_x)
- Problem Name: X - 関数的平方根
- difficulty: `8`
- tags: `FPS合成` `合成べき`
- tag_en: `FPS composition` `composition power`
- id: `atcoder/fps-24/fps_24_x`
- logged_at: `2026-07-03`

## memo

A surprising solution from hos's submission.

Let us write the $k$-fold composition of $F(x)\in \mathbb{F}_p(x)$ as $F^{(k)}(x)$. Then, $F^{(p)}(x)=x\pmod{x^p}$ holds.

Let's verify this. Let $V$ be the set of all polynomials of degree less than $p$, and let $\phi\colon V\longrightarrow V$ be defined by $g(x)\longmapsto g(F(x))$. Then, when $\phi$ is represented with respect to the basis $1,x,\ldots,x^{p-1}$, it becomes an upper triangular matrix whose diagonal entries are all $1$. Therefore $(\phi-\id)^p=0$, and from the commutativity of $\phi$ and $\id$ together with the binomial theorem, we get $\phi^p=\id$.

From here, the equivalence
$F(x)=G^{(2)(x)}\pmod {x^p} \iff F^{(p+1)/2}(x)=G(x)$
can be shown easily in both directions, $\implies$ and $\impliedby$.

In the end, to obtain the answer, it suffices to compose the input $F$ $(p+1)/2$ times, and the problem can be solved in $O(N\log^2N\log p)$ time.
