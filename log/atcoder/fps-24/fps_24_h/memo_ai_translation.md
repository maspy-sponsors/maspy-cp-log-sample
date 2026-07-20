> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# H - ジャンプ

- Problem: [atcoder/fps-24/fps_24_h](https://atcoder.jp/contests/fps-24/tasks/fps_24_h)
- Problem Name: H - ジャンプ
- difficulty: `5`
- tags: `包除原理` `EGF`
- tag_en: `inclusion-exclusion principle` `EGF`
- id: `atcoder/fps-24/fps_24_h`
- logged_at: `2026-07-02`

## memo

Let the generating function of the given movement rule be $F(x,y)$. Let $G(x,y)$ be the version that also allows $(0,0)$.
Since $G(x,y)=1+F(x,y)$, $G(x,y)$ is the one that is more convenient to handle systematically.

First, compute $b_n = [x^Ny^M]G^n$. This is easy if we treat each axis separately.
The goal is to compute $a_n = [x^Ny^M]F^n$, but since $F^n=(G-1)^n$, we have
$a_n=\sum_k\binom{n}{k}b_k(-1)^{n-k}$, and rearranging this shows that $a$ can be obtained from $b$ by an appropriate convolution.

By considering the interpretation of the exponential generating function, we can also directly formulate it in the form $B(x)=A(x)e^x$.
