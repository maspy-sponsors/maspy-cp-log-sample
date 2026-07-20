# D. diss_quack and Array Game

- 問題: [codeforces/2246/d](https://codeforces.com/contest/2246/problem/D)
- 問題名: D. diss_quack and Array Game
- difficulty: `4`
- tags: []
- id: `codeforces/2246/d`
- logged_at: `2026-07-13`

## memo

- Alice が全体 $/2$ を選択できる回数：lowbit の min. 
- それ以外：Bob が $2$ 番目に奇数がある状態にして，Alice は先頭に対する操作しかできない．

結局，

- ひとつの数に対してだけ操作する場合のコスト $c_i$
- 全部が $2^k$ で割り切れるような最大の $k$

を使って， $\sum c_i - kN$ のようなコストになります．

$c_i$ はおおよそ popcnt, topbit で書けます．

$K$ を固定して解きます． $a_i$ としてはまず最小の $2^K$ の倍数までインクリメントしたあとで，さらに $c_i$ を小さくするためのインクリメントが可能です．

しかし，popcnt, topbit のような評価関数なのでコストを大量にかけるのは明らかに無駄で，このフェーズのインクリメントは適当な小さな範囲を探索すればよいです．
