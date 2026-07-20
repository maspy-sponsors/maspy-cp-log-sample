# C. Inversion of a Subsequence

- 問題: [codeforces/2247/c](https://codeforces.com/contest/2247/problem/C)
- 問題名: C. Inversion of a Subsequence
- difficulty: `3`
- tags: []
- id: `codeforces/2247/c`
- logged_at: `2026-07-19`

## memo

入力は， $(0,0),(0,1),(1,0),(1,1)$ の個数に圧縮できます．

$0$ 手をまず判定します． $sum A = 0$ および $sum B=N$ を判定します．

$(0,1)$ が奇数組ならば， $1$ 手です．他のインデックスは好きに必要なところだけ操作に含めればよいので．

そうでなければ $2$ 手です． $(0,1)$ が奇数組ある状態に変換できることが少し場合分けをするとチェックできます．
