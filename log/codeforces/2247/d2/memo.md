# D2. XOR Sorting (Hard Version)

- 問題: [codeforces/2247/d2](https://codeforces.com/contest/2247/problem/D2)
- 問題名: D2. XOR Sorting (Hard Version)
- difficulty: `4`
- tags: []
- id: `codeforces/2247/d2`
- logged_at: `2026-07-19`

## memo

雑な log^2 が TLE，確かに制約が大きめ．

完全二分木の形のセグメント木を使って， $O(N+Q\log N)$ で解けます．

各ノードに min, max を持っておき，子をマージして親にするときに，「left max > right min」となっていたらそこで $k$ の必要量が増えます．

適切にモノイドを作れば，セグメント木に対する点変更と，prod_all という形で処理できます．
