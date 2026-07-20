# C - 数列

- 問題: [atcoder/fps-24/fps_24_c](https://atcoder.jp/contests/fps-24/tasks/fps_24_c)
- 問題名: C - 数列
- difficulty: `3`
- tags: []
- id: `atcoder/fps-24/fps_24_c`
- logged_at: `2026-07-02`

## memo

$[x^S](1+x+\cdots+x^{M})^N$ と立式できます．
そのまま fps pow のライブラリを使ってもよいですし， $(1-x^{M+1})^N\cdot (1-x)^{-N}$ と式変形を使ったあと二項定理と負の二項定理を使ってもよいです．
それぞれ， $O(S\log S)$ 時間， $O(S)$ 時間で解けます．
