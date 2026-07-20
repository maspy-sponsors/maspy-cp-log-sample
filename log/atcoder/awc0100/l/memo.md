# L - スケジュール調整

- 問題: [atcoder/awc0100/l](https://atcoder.jp/contests/awc0100/tasks/awc0100_l)
- 問題名: L - スケジュール調整
- tags: `two_sat` `reachability` `transitive_closure`
- difficulty: `4`
- id: `atcoder/awc0100/l`
- logged_at: `2026-06-28`

## memo

言い換えると「two sat の解で辞書順最小のものを求めてください」となります．

two sat は，各頂点 $v$ を $v_{0},v_{1}$ に倍化して $2N$ 個頂点からなる有向グラフを作り，どの $v_1,v_2$ も同じ強連結成分にいなければ解を持ちます．

二分探索で，解を持つような最大の $K$ は求まります．

このあとは $1$ 文字ずつ決めていきます．例えば「 $v$ を $0$ に決定する」というのは， $v_1\to v_0$ に相当する辺を追加することに相当します．

「 $1$ 辺追加しようとする． $w_0\to w_1, w_1\to w_0$ という形の reachability が生じそうだったら失敗． $0$ にしようとして失敗したら $1$ を追加」

をやればよいです．各時点での reachability を表す行列（transitive closure）を保持し，辺追加に対しては適当な bitset 処理で判定や更新ができます．

制約を勘違いしていたのですが，辺を足すたびに $0$ から two sat してもよい制約だったみたいです．
