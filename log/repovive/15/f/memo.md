# 15F. Magnetic Path

- 問題: [repovive/15/f](https://repovive.com/contests/15/problems/F)
- 問題名: 15F. Magnetic Path
- difficulty: `4`
- tags: []
- id: `repovive/15/f`
- logged_at: `2026-07-06`

## memo

だいたい距離 $2$ ずつ近づくようにしますが， $N$ が奇数のときには $1$ 回だけどちらかを停止して進めます．

$2$ 頂点の位置の組を状態として dp で計算しました．ステップ数に対して距離が減ってない状態を枝狩りします．
