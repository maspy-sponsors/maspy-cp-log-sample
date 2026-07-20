# G. Simple Problem

- 問題: [codeforces/2225/g](https://codeforces.com/contest/2225/problem/G)
- 問題名: G. Simple Problem
- difficulty: `6`
- tags: `整数論` `構築`
- id: `codeforces/2225/g`
- logged_at: `2026-07-02`

## memo

【未証明パートあり】

互いに素だと任意の始点でパスを作れる，というのを帰納法で示していく感じです．

$n-1$ 個時点での最大公約数を $g$ として， $n$ 番目の数を $c$ とします．
$g=1$ だったら $n-1$ 個時点でのそれが満たします．

- $x\equiv 0\pmod{g}$ となる $x$ 全体でパスを作る
- $x\equiv c\pmod{g}$ となる $x$ 全体でパスを作る
- $x\equiv 2c\pmod{g}$ となる $x$ 全体でパスを作る

として結合します．パスの間の移動は $x\to x+c$ とします．

このとき要請として， $x+c<N$ が来ます．
これが大丈夫なのかは検証していないのですが，帰納法の base step でパスの終点を最小化しておけばたぶん大丈夫なんじゃないかな？としたら通りました（きちんと証明していません）．
