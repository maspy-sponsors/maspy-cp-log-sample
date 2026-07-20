# I. Kevin and Nivek

- 問題: [codeforces/2061/i](https://codeforces.com/contest/2061/problem/I)
- 問題名: I. Kevin and Nivek
- difficulty: `8`
- tags: `2次元dpの分割統治高速化`
- id: `codeforces/2061/i`
- logged_at: `2026-07-19`

## memo

$i$ round 追えた時点での勝数を $j$ として，dp[i][j] という dp テーブルは考えられると思います．

dp[0] から dp[N] への遷移を分割統治により高速化します．

dp[L][a,b) から dp[R] への遷移を行うという再帰関数を設計します．

今回の設定では，端の方 $[a,c), [d,b)$ のような区間からの遷移は，min-plus convolution でまとめて行えます．
間の $[c,d)$ 部分からの遷移は， $L\to M\to R$ に分解して遷移します．
