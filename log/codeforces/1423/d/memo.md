# D. Does anyone else hate the wind?

- 問題: [codeforces/1423/d](https://codeforces.com/contest/1423/problem/D)
- 問題名: D. Does anyone else hate the wind?
- difficulty: `4`
- tags: []
- id: `codeforces/1423/d`
- logged_at: `2026-07-14`

## memo

単純な dp です．dp[day][row][col] を，可能な HP の max と定めるという要領です．

これで， $O(NM\cdot \text{max day})$ というような計算量になりますが，day は $KT$ で抑えられるのでよいです．

風が吹いた場合の行先については，問題文通りに厳密に読むと少し違うのではないかと思ったのですが．類推した方が良いと思います．
