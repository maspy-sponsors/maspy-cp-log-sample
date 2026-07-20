# K. Lonely Numbers

- 問題: [codeforces/1423/k](https://codeforces.com/contest/1423/problem/K)
- 問題名: K. Lonely Numbers
- difficulty: `3`
- tags: []
- id: `codeforces/1423/k`
- logged_at: `2026-07-14`

## memo

合成数は lonely ではありません．実際 $a=px$ かつ $2\leq p, x$ であるとき， $b=p(x-1)$ とすれば三角形が成立します．

よって素数 $p$ を候補とすればよいです． $\gcd$ としてありうるのは $1,p$ のどちらかしかなくて，これらの場合を考えれば， $p$ が lonely でなくなるのは， $(p,p^2)$ の場合だと分かります．ここから，適当な区間内の素数の個数が答となります．
