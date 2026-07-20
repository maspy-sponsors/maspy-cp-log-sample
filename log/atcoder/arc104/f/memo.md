# F - Visibility Sequence

- 問題: [atcoder/arc104/f](https://atcoder.jp/contests/arc104/tasks/arc104_f)
- 問題名: F - Visibility Sequence
- difficulty: `5`
- tags: `Cartesian_Tree` `タイブレイク` `区間dp`
- id: `atcoder/arc104/f`
- logged_at: `2026-07-03`

## memo

おおよそ，Cartesian Tree としてありうるのは何通り？ということです．
ただしタイブレイクは慎重にする必要があります．同じ値は右側にあるほど大きいと見なすとする，とします．

ある Cartesian Tree の木構造が，数列 $H$ から生成できますか？という判定問題をまず考えます．
するとこれは，bottom up になるべく小さい値を割り当てていく貪欲によって判定されます．

そこで，

- dp[l][r][x]: $[L,R)$ を根付き木にする方法であって根の値が $x$ にする方法の数え上げ

という形で区間 dp ができます．
