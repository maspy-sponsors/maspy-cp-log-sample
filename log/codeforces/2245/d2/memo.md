# D2. Construct an Array (Hard Version)

- 問題: [codeforces/2245/d2](https://codeforces.com/contest/2245/problem/D2)
- 問題名: D2. Construct an Array (Hard Version)
- difficulty: `7`
- tags: `構築` `potential` `頂点倍加`
- id: `codeforces/2245/d2`
- logged_at: `2026-07-17`

## memo

いや難しいが．

まず必要条件として，「+-+-+-」の形の交互サイクルがあるとダメです．
これは，次のグラフの有向サイクルとして記述できます．

- $+$ 辺： $2i\to 2j+1$．
- $-$ 辺： $2i+1\to 2j$．

逆にいえばこれらがない場合，DAG です．
DAG ということは負閉路がないので，辺重みをつけてポテンシャルが定義できます．

- $+$ 辺について： $p[2j+1] \leq p[2i], p[2i+1]\leq p[2j]$
- $-$ 辺について： $p[2j] \leq p[2i+1]-1, p[2i]\leq p[2j+1]-1$

となるようにポテンシャルをつけて， $a[i]=p[2i]-p[2i+1]$ とすれば，求める構築が達成できます．


ABC461G とかなり近い？
