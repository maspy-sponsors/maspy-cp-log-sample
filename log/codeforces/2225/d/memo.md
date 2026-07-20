# D. Exceptional Segments

- 問題: [codeforces/2225/d](https://codeforces.com/contest/2225/problem/D)
- 問題名: D. Exceptional Segments
- difficulty: `4`
- tags: `区間XORが0`
- id: `codeforces/2225/d`
- logged_at: `2026-07-01`

## memo

$l,r$ の偶奇を考えます． $2^1$ の位以上の部分がどうなるかを考えると，だいたいのものが $2$ 個ずつ出てきて打ち消しあいます．その上で全体で $0$ になって欲しいと考えると，次のようなパターンだけだと分かります．

- $l$ が偶数かつ $r$ が奇数で $r-l+1$ が $4$ の倍数．
- $l=1$ かつ $r\equiv 3\pmod{4}$．（ $l=0$ として上のパターンと解釈できる）
