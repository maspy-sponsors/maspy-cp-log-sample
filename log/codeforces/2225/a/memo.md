# A. A Number Between Two Others

- 問題: [codeforces/2225/a](https://codeforces.com/contest/2225/problem/A)
- 問題名: A. A Number Between Two Others
- difficulty: `2`
- tags: `整数論計算量`
- id: `codeforces/2225/a`
- logged_at: `2026-07-01`

## memo

$x$ の倍数にしか興味がないので全体を $x$ で割って考えると， $y$ の約数ではない何かを探すという問題になります．

$1,2,\ldots,k$ まで探索して見つからないのは $y$ がそれらの最小公倍数の倍数のときですが，最小公倍数が $\exp(k(1+o(1)))$ 程度になること

https://info.atcoder.jp/entry/algorithm_lectures/prime_related_complexity

を考慮すれば，愚直に試す解法が十分高速です．
