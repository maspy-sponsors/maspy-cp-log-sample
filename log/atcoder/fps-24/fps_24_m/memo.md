# M - 連結グラフ

- 問題: [atcoder/fps-24/fps_24_m](https://atcoder.jp/contests/fps-24/tasks/fps_24_m)
- 問題名: M - 連結グラフ
- difficulty: `4`
- tags: `グラフ数え上げ` `FPS_exp`
- id: `atcoder/fps-24/fps_24_m`
- logged_at: `2026-07-02`

## memo

$A(x)$ を連結グラフの EGF， $B(x)$ を任意のグラフの EGF とします（数え上げを $a_n,b_n$ としたときの $\sum \frac{a_n}{n!}x^n$, $\sum \frac{b_n}{n!}x^n$）．

すると，L とほとんど同じように， $B(x)=\exp A(x)$ が分かります．

今回は $B(x)$ が簡単に求まり， $B$ を既知として $A$ が知りたいという状況です．これは $A(x)=\log B(x)$ と計算できます．
