# 15D. Distant Transfers

- 問題: [repovive/15/d](https://repovive.com/contests/15/problems/D)
- 問題名: 15D. Distant Transfers
- difficulty: `3`
- tags: `exchange_argument`
- id: `repovive/15/d`
- logged_at: `2026-07-06`

## memo

$l$ にある余分と $r$ にある不足をマッチングすると考えます．

あるインデックスが不足，余分の両方を受け持つならばそれを解消してもよいです．

すると，余分，不足分をそれぞれインデックス昇順に並べて，そのまま順でマッチングしていくのが最適になります．
逆転している対があれば解消してもスコアが悪くならないからです．
