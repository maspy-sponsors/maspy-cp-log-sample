# E. Build a Tree

- 問題: [codeforces/2247/e](https://codeforces.com/contest/2247/problem/E)
- 問題名: E. Build a Tree
- difficulty: `4`
- tags: `構築` `木の構築` `順列の構築`
- id: `codeforces/2247/e`
- logged_at: `2026-07-19`

## memo

パスグラフだけで作れます．

ある頂点について

- マイナス：「右から来て右に出る」
- プラス：「左から来て左に出る」

とすると，

`---00+000++`

のような構成で全部作れます．
