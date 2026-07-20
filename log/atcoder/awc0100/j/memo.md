# J - 道路ネットワークの整備

- 問題: [atcoder/awc0100/j](https://atcoder.jp/contests/awc0100/tasks/awc0100_j)
- 問題名: J - 道路ネットワークの整備
- tags: `HLD` `パスクエリ`
- difficulty: `4`
- id: `atcoder/awc0100/j`
- logged_at: `2026-06-28`

## memo

パス上の辺に， $1$ 加算するというのと min query というのの $2$ 種のクエリが来ます．例えば HLD でパスクエリを処理すればよいです．

https://info.atcoder.jp/entry/algorithm_lectures/heavy_light_decomposition

一応，加算フェーズ，パスクエリフェーズと分かれているので，もうちょっと解法選択肢は広いです．
例えば $0$ からこの問題のためだけに実装するならば，ダブリング（binary lifting）の方が手軽かもしれません．
