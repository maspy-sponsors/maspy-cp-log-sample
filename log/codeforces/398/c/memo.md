# C. Tree and Array

- 問題: [codeforces/398/c](https://codeforces.com/contest/398/problem/C)
- 問題名: C. Tree and Array
- difficulty: `7`
- tags: `帰納的構築`
- id: `codeforces/398/c`
- logged_at: `2026-07-08`

## memo

$2n$ 頂点増やすと good pair が $n$ 組増える．という構造があればよいです．
$N$ 頂点の木で頂点 $N$ が good pair に使われていないときに， $N+2n$ 頂点の木で頂点 $N+2n$ が good pair に使われていないようなものを作ろうとします．これには適当な $2n$ 頂点のパーツがあればできます．

あとは探索です． $N$ が十分大きければ $8$ 頂点増やせることが分かり，小さいところも乱択で見つけて埋め込みました（ $t$ の値がかなり小さい範囲で探索すると結構たくさん解があることが分かります）．
