# No.3550 Another Rurumaru Function Problem

- 問題: [yukicoder/3550](https://yukicoder.me/problems/no/3550)
- 問題名: No.3550 Another Rurumaru Function Problem
- difficulty: `4`
- tags: []
- id: `yukicoder/3550`
- logged_at: `2026-07-14`

## memo

答えを上位桁から順に決めていきます．

$1$ にしなければいけない目標桁を固定して判定します．
目標の偶数桁が $1$ ならば，使う $A_i$ もそういう数限定です．そういうものを全部使って奇数桁が大丈夫かどうかチェックします．
