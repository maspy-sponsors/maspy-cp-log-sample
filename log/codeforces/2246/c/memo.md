# C. 0mar and Alternating Sums

- 問題: [codeforces/2246/c](https://codeforces.com/contest/2246/problem/C)
- 問題名: C. 0mar and Alternating Sums
- difficulty: `4`
- tags: []
- id: `codeforces/2246/c`
- logged_at: `2026-07-13`

## memo

結構ややこしや．

まず全体から偶数個とるパターンを考えます．

+-/+-/+-

と区切ることで，総和が $0$ 以下になることが分かります．すると総和が $0$ になるのは， $2$ 個ずつでマッチングになっている場合しかありません．


次に全体から奇数個とるパターンを考えます．

+/-+/-+/-+/

と区切ると，先頭のブロック以外は交代和への寄与が非負です．よって

-1, [a,a], [b,b], ..., [c,c], [x,x+1], [d,d], [e,e], ...

のようなパターンしかありません． $x$ を固定するごとに適当な計算をします．
