# F - Two Strings

- 問題: [atcoder/abc272/f](https://atcoder.jp/contests/abc272/tasks/abc272_f)
- 問題名: F - Two Strings
- difficulty: `4`
- tags: []
- id: `atcoder/abc272/f`
- logged_at: `2026-07-08`

## memo

$SSTT$ の suffix array を作りました．

suffix array の位置で自身より手前，または後ろにあるけど lcp がちょうど $N$ である範囲ということで，対応する区間が求まります．
