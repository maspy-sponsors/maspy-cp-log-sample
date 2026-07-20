# P - ボール

- 問題: [atcoder/fps-24/fps_24_p](https://atcoder.jp/contests/fps-24/tasks/fps_24_p)
- 問題名: P - ボール
- difficulty: `4`
- tags: `EGF` `多点評価`
- id: `atcoder/fps-24/fps_24_p`
- logged_at: `2026-07-02`

## memo

答は次のように立式出来ます．

- 答は $N![x^N]\prod_{0\leq i\leq m}f_i(x)$，ただし
  - $f_0(x)=\sum_{n=0}^{K}\frac{1}{n!}x^n$
  - $f_i(x)=\sum_{n=0}^{\infty}\frac{1}{n!}x^n=e^x$

よって少し整理すれば，答は $N![x^N]f_0(x)e^{mx}$ です．

$e^{mx}=\sum_n\frac{m^n}{n!}x^n$ から，答を $\mathrm{polynomial}(m)$ の形で表せます．あとは多点評価を使えば， $O(m\log^2 m+n\log n)$ 時間で解けます．
