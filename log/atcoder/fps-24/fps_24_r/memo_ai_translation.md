> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# R - ランダムウォーク

- Problem: [atcoder/fps-24/fps_24_r](https://atcoder.jp/contests/fps-24/tasks/fps_24_r)
- Problem Name: R - ランダムウォーク
- difficulty: `5`
- tags: `パス上のwalk` `walkの母関数` `巡回畳み込み`
- tag_en: `walk on a path` `generating function of walks` `cyclic convolution`
- id: `atcoder/fps-24/fps_24_r`
- logged_at: `2026-07-02`

## memo

Let $n=2^N$.

Although it may seem that the transition probabilities at the ends are different, the following figure resolves this. We can think of it as the problem of "performing a random walk on a cycle and observing only the $x$-coordinate."

![Figure](fig/R.drawio.png)

In the end, it is enough to compute $(x+x^{-1})^{T}\pmod{1-x^{2n}}$.

If we compute this by repeated squaring, the complexity would seem to be something like $O(n\log n\log T)$, but under the constraint $n=2^N$, there is a simpler method.

Since FFT converts the relationship of cyclic convolution into pointwise products, for the $T$-th power computation for cyclic convolution as in this problem, we can perform an FFT with period $2^{N+1}$, take the $T$-th power at each point, and then return by IFFT.

Although it is less well known than polynomial multiplication, polynomial multiplication is usually understood by deriving it using the relationship between FFT and cyclic convolution, so if you understand the relationship between polynomial multiplication and FFT, I think you can also understand this.
