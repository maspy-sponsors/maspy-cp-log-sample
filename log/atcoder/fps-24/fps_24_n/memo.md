# N - 硬貨 2

- 問題: [atcoder/fps-24/fps_24_n](https://atcoder.jp/contests/fps-24/tasks/fps_24_n)
- 問題名: N - 硬貨 2
- difficulty: `4`
- tags: `FPS_log`
- id: `atcoder/fps-24/fps_24_n`
- logged_at: `2026-07-02`

## memo

答は次のように立式出来ます：

$$[x^N] \prod_i (1+x^i+x^{2i}+\cdots+x^{iA_i})$$

これを $\frac{1-x^{i(A+1)}}{1-x^A}$ のように表すと， $(1-x^a)^{\pm 1}$ の形の FPS を $O(N)$ 個かければよいことになります．

$\log (1-x^A)$ が $N$ 次以下の項を $O(N/A)$ 個程度しか持たないから， $\log$ を求めて $\exp$ に入れるという要領で $O(N\log N)$ 時間で解けます．
