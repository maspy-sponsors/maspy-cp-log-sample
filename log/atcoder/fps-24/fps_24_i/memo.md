# I - スコア

- 問題: [atcoder/fps-24/fps_24_i](https://atcoder.jp/contests/fps-24/tasks/fps_24_i)
- 問題名: I - スコア
- difficulty: `4`
- tags: `多項式総積`
- id: `atcoder/fps-24/fps_24_i`
- logged_at: `2026-07-02`

## memo

$[x^K]\prod_i(1+A_ix)$ です．このような総積は，分割統治などを利用して次数のバランスを保った計算手順をとることで， $O(N\log^2 N)$ 時間で計算できます．
