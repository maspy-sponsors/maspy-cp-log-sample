# B - Adjacent Tiles

- 問題: [atcoder/arc224/b](https://atcoder.jp/contests/arc224/tasks/arc224_b)
- 問題名: B - Adjacent Tiles
- difficulty: `3`
- tags: `bounding_box`
- id: `atcoder/arc224/b`
- logged_at: `2026-07-12`

## memo

証明まで含めるとちょっと難しそう．

bounding box の型を $(H,W)$ としてこれを固定します．

スコアは次のように考えられます．

- 各正方形から見て，上にも正方形があれば $1$ 点獲得．
- 各正方形から見て，左にも正方形があれば $1$ 点獲得．

こうすると自明な上界が $2N$ 点です．ただし，

- 各行で最も左の正方形
- 各列で最も上の正方形

については獲得できないスコアがあって，ここから $H,W$ を固定したときに $N-H-W$ が上界になります．

それっぽく敷き詰めると等号成立にできて，結局次の形の問題になります．

- $2N-H-W$ を最大化せよ．
- ただし $H+W-1\leq N\leq HW$．

$H+W-1\leq N$ は無視しても結果的に大丈夫です．
