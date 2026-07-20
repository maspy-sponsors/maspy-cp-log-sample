# D - Multiset Mean

- 問題: [atcoder/arc104/d](https://atcoder.jp/contests/arc104/tasks/arc104_d)
- 問題名: D - Multiset Mean
- difficulty: `4`
- tags: `戻すdp`
- id: `atcoder/arc104/d`
- logged_at: `2026-07-03`

## memo

$x$ ずつ引いた上で，和を $0$ にする方法を数えます．

$x$ について差分更新することを考えると，ある価値の整数を削除，ある価値の整数を追加ということになります．

母関数を考えると， $\frac{1-x^{n(K+1)}}{1-x}$ の形の有理式でかけたり割ったりしながら適当な係数を出力すればよいです．
