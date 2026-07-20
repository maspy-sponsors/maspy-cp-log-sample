> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# V - 12 方向

- Problem: [atcoder/fps-24/fps_24_v](https://atcoder.jp/contests/fps-24/tasks/fps_24_v)
- Problem Name: V - 12 方向
- difficulty: `7`
- tags: `2変数FPS`
- tag_en: `two-variable FPS`
- id: `atcoder/fps-24/fps_24_v`
- logged_at: `2026-07-02`

## memo

First, we can separate the problem into the following two types:

- Using only even directions, that is, moves with $i=0,2,4,6,8,10$, and reaching $(H,0)$.
- Using only odd directions, that is, moves with $i=1,3,5,7,9,11$, and reaching $(0,W)$.

If you know cyclotomic field theory, this is immediately clear from $\mathbb{Q}(\zeta_{3})\subsetneq \mathbb{Q}(\zeta_{12})$. It can also be proved relatively easily at the high-school-math level by looking at each axis separately. (Looking in the $x$ direction, only moves by rational multiples of $1$ and $\sqrt{3}$ occur, and to reach $H$, all movement coming from $\sqrt{3}$ must cancel out.)

Therefore, it is enough to solve the following: using only even-direction moves, count the ways to reach $(H,0)$ in $n$ steps for $n=0,1,\ldots,N$.

By using a suitable oblique coordinate system, this reduces to the following: compute $[x^H](x+y+xy+x^{-1}+y^{-1}+x^{-1}y^{-1})^n$ for $n=0,1,\ldots,N$. This situation is a little similar to Problem H.

Let $F(x,y)=x+y+xy+x^{-1}+y^{-1}+x^{-1}y^{-1}$. Then, rather than this, it is more convenient to handle

$$G(x,y)=2+F(x,y)=(x^{1/2}+x^{-1/2})(y^{1/2}+y^{-1/2})((xy)^{1/2}+(xy)^{-1/2})$$

First, a plan is to enumerate $[x^H]G(x,y)^n$ and then use that to enumerate $[x^H]F(x,y)^n$. Enumerating $[x^H]G(x,y)^n$, using the factorized form and the binomial theorem, becomes a computation of the type: "add up many products of three suitable binomial coefficients following a rule of a suitable linear form," and writing the expression shows that it can be obtained by convolution.

Putting this together, we see that the problem can be solved in $O(N\log N)$ time.
