# C - Reverse Permutation

- 問題: [atcoder/abc465/c](https://atcoder.jp/contests/abc465/tasks/abc465_c)
- 問題名: C - Reverse Permutation
- difficulty: `3`
- tags: `deque` `シミュレーション`
- id: `atcoder/abc465/c`
- logged_at: `2026-07-04`

## memo

次のように言い換えると簡単です．

- $i$ を push back．
- 文字に応じて reverse したりしなかったりする．

全体を reverse する代わりに，reverse しているかどうかのフラグだけ持っておき，先頭または末尾への追加とします．
例えば deque を使うとこの過程を自然にシミュレーションできます．
