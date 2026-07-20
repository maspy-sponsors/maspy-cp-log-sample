# D - Angst for All Pairs

- 問題: [atcoder/arc224/d](https://atcoder.jp/contests/arc224/tasks/arc224_d)
- 問題名: D - Angst for All Pairs
- difficulty: `3`
- tags: []
- id: `atcoder/arc224/d`
- logged_at: `2026-07-12`

## memo

カードから数を見るんじゃなくて，各 $x\in [1,K]$ に対して $x$ を書くカード集合を考えます．

すると単に，「各 $x$ に相異なる集合を割り当てる．」ということになります．

popcnt の小さな集合を $K$ 個用意して，コストの大きい数に小さな集合を割り当てていけばよいです．
