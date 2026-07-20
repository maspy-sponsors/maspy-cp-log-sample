# F. Familiar?

- 問題: [codeforces/2245/f](https://codeforces.com/contest/2245/problem/F)
- 問題名: F. Familiar?
- difficulty: `7`
- tags: `区間dp` `Cartesian_Tree`
- id: `codeforces/2245/f`
- logged_at: `2026-07-17`

## memo

かなり気づかなかった．

Cartesian Tree を考えると， $a_i$ は，左の子から右方向に伸びるパス頂点数として解釈できます．

これでまず，4 乗計算量で解けます．dp の状態として，

- $dp[l][r][k]$：区間 $[l,r)$ を根付き木にする．根から右方向に伸びるパス頂点数が $k$ である．

となります．ここで，

- $a_r=x$ のとき， $0\leq k\leq x$ だけが重要
- $a_r=-1$ のとき， $\sum_k dp[l][r][k]$ だけが重要
- 解があるなら $a_i\neq -1$ のところでの $\sum a_i$ は $n$ 以下になっているはず

ということから，この 4 乗 dp はほとんどそのまま計算量が 3 乗になります．空間も 2 乗になります．
