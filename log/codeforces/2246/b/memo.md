# B. ezraft and Array

- 問題: [codeforces/2246/b](https://codeforces.com/contest/2246/problem/B)
- 問題名: B. ezraft and Array
- difficulty: `3`
- tags: `構築` `帰納的構成`
- id: `codeforces/2246/b`
- logged_at: `2026-07-13`

## memo

総和を $S$ として， $b_i=S/a_i$ とすると， $\sum 1/b_i=1$ です．
LCM をおさえてこういう単位分数を作る問題だと思います．

だいたいこんな感じで作れます．

- $2,4,8,16,32,32$ としてみるとこれは distinct ではないが逆数和は $1$ である．
- $2,4,8,16,32,48,96$ とすると distinct かつ逆数和は $1$ である．

$N=2$ だけ不可能ケースであとは上の要領で．
