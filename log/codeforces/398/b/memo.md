# B. Painting The Wall

- 問題: [codeforces/398/b](https://codeforces.com/contest/398/problem/B)
- 問題名: B. Painting The Wall
- difficulty: `3`
- tags: []
- id: `codeforces/398/b`
- logged_at: `2026-07-08`

## memo

ある時点での状態は，少なくともひとつのマスが塗られた行の個数・列の個数によって表されます．すると 
$O(N^2)$ 頂点の DAG と遷移確率も簡単に分かっていて，ゴールするまでの回数期待値を求めるという問題になり，適当な DP で解けます．
