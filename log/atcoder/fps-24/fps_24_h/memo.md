# H - ジャンプ

- 問題: [atcoder/fps-24/fps_24_h](https://atcoder.jp/contests/fps-24/tasks/fps_24_h)
- 問題名: H - ジャンプ
- difficulty: `5`
- tags: `包除原理` `EGF`
- id: `atcoder/fps-24/fps_24_h`
- logged_at: `2026-07-02`

## memo

与えられた移動ルールの母関数を $F(x,y)$ とします． $(0,0)$ も認めたものを $G(x,y)$ とします．
$G(x,y)=1+F(x,y)$ で，規則的に扱いやすいのは $G(x,y)$ の方です．

まず $b_n = [x^Ny^M]G^n$ を求めます．これは軸ごとに分けて扱えば簡単です．
$a_n = [x^Ny^M]F^n$ を求めることが目標ですが， $F^n=(G-1)^n$ より $a_n=\sum_k\binom{n}{k}b_k(-1)^{n-k}$ となって，これを整理すると $a$ は $b$ から適当な畳み込みで求まることが分かります．

指数型母関数の意味付けを考えて直接 $B(x)=A(x)e^x$ の形の立式をすることもできます．
