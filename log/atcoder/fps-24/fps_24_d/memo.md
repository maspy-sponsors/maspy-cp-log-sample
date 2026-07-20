# D - 数列 2

- 問題: [atcoder/fps-24/fps_24_d](https://atcoder.jp/contests/fps-24/tasks/fps_24_d)
- 問題名: D - 数列 2
- difficulty: `4`
- tags: []
- id: `atcoder/fps-24/fps_24_d`
- logged_at: `2026-07-02`

## memo

$0\to a_1\to a_2\to \cdots \to a_N\to M$ という移動を考えると，

- 非負整数
- 正の奇数が $N-1$ 個
- 非負整数

の総和として $M$ を作る問題になります．よって 

$$[x^M]\frac{1}{1-x}\cdot \left(\frac{x}{1-x^2}\right)^{N-1}\cdot \frac{1}{1-x}$$

を求める問題です．例えば真ん中の $N-1$ 乗を計算したあと累積和 $2$ 回として実装できます．
