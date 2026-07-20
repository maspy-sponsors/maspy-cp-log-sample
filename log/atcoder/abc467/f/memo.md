# F - Email Scheduling Optimization

- 問題: [atcoder/abc467/f](https://atcoder.jp/contests/abc467/tasks/abc467_f)
- 問題名: F - Email Scheduling Optimization
- difficulty: `4`
- tags: `ソート順の決定` `値をインデックスにする`
- id: `atcoder/abc467/f`
- logged_at: `2026-07-18`

## memo

$(A_1,B_1),(A_2,B_2)$ の並び順について考察すると， $B$ について降順ソートするのが最適であると分かります．

降順ソートされている列については答の計算はセグメント木で行えます．

すべてを先読み座圧して， $B_i$ の値をインデックスとするセグメント木で全てを処理できます．
