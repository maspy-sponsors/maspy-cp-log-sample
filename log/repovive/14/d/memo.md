# 14D. Sleeping Journey

- 問題: [repovive/14/d](https://repovive.com/contests/14/problems/D)
- 問題名: 14D. Sleeping Journey
- difficulty: `4`
- tags: `BFS`
- id: `repovive/14/d`
- logged_at: `2026-06-30`

## memo

まず各点からの距離を求めておきます．各頂点にはこの値が書かれていると思って，グラフ構造は忘れてよいです．

値を $-1$ する，または， $N$ 個からのランダムな値を抽選する．というのが行動です．

$x\leq K$ ならば $-1$， $K < x$ ならば抽選．というパターンを調べればよいです．

mod は最後にとるだけで，途中の比較は有理数比較です．
