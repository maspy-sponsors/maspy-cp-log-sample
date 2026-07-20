# H - 都市の巡回調査

- 問題: [atcoder/awc0100/h](https://atcoder.jp/contests/awc0100/tasks/awc0100_h)
- 問題名: H - 都市の巡回調査
- tags: `シミュレーション`
- difficulty: `2`
- id: `atcoder/awc0100/h`
- logged_at: `2026-06-28`

## memo

問題文の通りにシミュレーションします．

「未調査の最重要都市」を求めるには，各都市の行先全体と，visited 配列を管理すればよいです．
同じ都市からの検索は $1$ 度だけなので，通常の実装では計算量の心配はないでしょう．

計算量としては出発都市を決めるところに工夫が必要で，ここは priority queue やソート済配列などで処理できます．
