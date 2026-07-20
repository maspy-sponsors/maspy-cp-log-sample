# E. Covering Points with Circles

- 問題: [codeforces/2225/e](https://codeforces.com/contest/2225/problem/E)
- 問題名: E. Covering Points with Circles
- difficulty: `4`
- tags: `乱択アルゴリズム` `最密充填` `幾何構築`
- id: `codeforces/2225/e`
- logged_at: `2026-07-01`

## memo

最密充填的な並べ方をします． $H$ を $\sqrt{3}R$ 程度にとり， $(iR,jH)$ であって $i+j\equiv 0\pmod{2}$ というようにします．

これをランダムにずらすと，各点ごとに， $90.6\%$ 程度の確率で被覆されます．ずらす量を乱択して，目標の $89\%$ 以上になるまでやります．

ずらす量が整数なので，この条件化でその確率になるかは検証していないのですが，まあそのための $R\geq 100$ という問題設定だと信じました．
