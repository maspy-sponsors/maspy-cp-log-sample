# E - Adjacent Sums (hard)

- 問題: [atcoder/abc467/e](https://atcoder.jp/contests/abc467/tasks/abc467_e)
- 問題名: E - Adjacent Sums (hard)
- difficulty: `4`
- tags: []
- id: `atcoder/abc467/e`
- logged_at: `2026-07-18`

## memo

足す回数 $(x_i)$ （mod M で考える）について， $x_i+x_{i+1}$ がいくつという制約があります．

ひとつの（最適とは限らない）解をとると，

- 奇数インデックスの $x_i$ に $+c$
- 偶数インデックスの $x_i$ に $-c$

がすべての解を与えます． $c$ を最適化すると思います．

$c$ の関数として見ると区分的に $1$ 次関数なので，何かが起こる境界だけ計算すればよいです．
あとはソートや二分探索で処理できます．
