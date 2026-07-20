# X - 関数的平方根

- 問題: [atcoder/fps-24/fps_24_x](https://atcoder.jp/contests/fps-24/tasks/fps_24_x)
- 問題名: X - 関数的平方根
- difficulty: `8`
- tags: `FPS合成` `合成べき`
- id: `atcoder/fps-24/fps_24_x`
- logged_at: `2026-07-03`

## memo

hos さんの提出からびっくり解法．

$F(x)\in \mathbb{F}_p(x)$ の $k$ 回合成を $F^{(k)}(x)$ と書くことにします．このとき， $F^{(p)}(x)=x\pmod{x^p}$ が成り立ちます．

このことを確かめましょう． $V$ を $p$ 次未満の多項式全体として， $\phi\colon V\longrightarrow V$ を $g(x)\longmapsto g(F(x))$ とします．このとき， $\phi$ を基底 $1,x,\ldots,x^{p-1}$ で成分表示すると，対角成分を $1$ とする上三角行列になります．よって $(\phi-\id)^p=0$ となり， $\id$ と $\phi$ の可換性および，二項定理から $\phi^p=\id$ となります．

ここから， $F(x)=G^{(2)(x)}\pmod {x^p} \iff F^{(p+1)/2}(x)=G(x)$ という同値が， $\implies$ も $\impliedby$ もどちらも容易に示せます．

結局答を求めるには入力の $F$ を $(p+1)/2$ 回合成すればよく， $O(N\log^2N\log p)$ 時間で解けます．
