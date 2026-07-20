# B. Delete and Concatenate

- 問題: [codeforces/2245/b](https://codeforces.com/contest/2245/problem/B)
- 問題名: B. Delete and Concatenate
- difficulty: `4`
- tags: []
- id: `codeforces/2245/b`
- logged_at: `2026-07-17`

## memo

まず，各要素から $c$ を引いてしまった上で操作コストは $0$ としてよいです．

「とるもの」を $1$ として「とらないもの」を $0$ としたときに実現可能な $01$ 列を考えます．

すると， $1$ の個数が $0$ の個数以上であるという必要条件が出てきます．
これは十分条件にもなっていて， $0$ がある限り $01,10$ のどちらかを削除していくという方法で達成できます．
