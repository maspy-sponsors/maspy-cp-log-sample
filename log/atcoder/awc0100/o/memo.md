# O - 円環石板の結合

- 問題: [atcoder/awc0100/o](https://atcoder.jp/contests/awc0100/tasks/awc0100_o)
- 問題名: O - 円環石板の結合
- tags: `monge` `Knuth_Yao_SpeedUp`
- difficulty: `6`
- id: `atcoder/awc0100/o`
- logged_at: `2026-06-28`

## memo

これもほぼ有名既出そのままです．次の問題では問題ページに解説があります．

https://atcoder.jp/contests/atc002/tasks/atc002_c

解説の $O(n^2)$ 解法を使います．Knuth-Yao SpeedUp といいます．これで区間ごとの最適解を得ることができます．

今回は円環ですが，長さ $2n$ に拡張して置き， $[i,i+n)$ の場合の解の最小値をとればよいです．
