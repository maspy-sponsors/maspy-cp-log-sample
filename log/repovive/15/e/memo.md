# 15E. Synchronized Inversions

- 問題: [repovive/15/e](https://repovive.com/contests/15/problems/E)
- 問題名: 15E. Synchronized Inversions
- difficulty: `3`
- tags: `転倒数`
- id: `repovive/15/e`
- logged_at: `2026-07-06`

## memo

隣接スワップで $-2,0,2$ だけ増減するため，max, min の間を同 parity で全部作れることになります．

最大，最小はそれぞれ $a$ が昇順または降順にソートした場合に達成されます．これはそうするのが単にペアごとに最適だからです．
