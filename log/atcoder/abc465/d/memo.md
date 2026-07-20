# D - X to Y

- 問題: [atcoder/abc465/d](https://atcoder.jp/contests/abc465/tasks/abc465_d)
- 問題名: D - X to Y
- difficulty: `2`
- tags: `K進法`
- id: `atcoder/abc465/d`
- logged_at: `2026-07-04`

## memo

$K$ 進法表記の文字列で操作を言い換えます（ただし $0$ は敢えて空文字列扱いとします）．

$0$ を $0$ に変更するというのをやらないことにすると，操作は文字列末尾への追加削除となります．
文字列のうちで何文字残せるか（文字列の lcp）を計算します．
