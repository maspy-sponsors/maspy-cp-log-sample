# 14C. Range Reversal

- 問題: [repovive/14/c](https://repovive.com/contests/14/problems/C)
- 問題名: 14C. Range Reversal
- difficulty: `4`
- tags: `区間反転`
- id: `repovive/14/c`
- logged_at: `2026-06-30`

## memo

区間内で，00, 11 の個数を数えて $a$, $b$ とします．

まず，reverse は隣接関係を高々 $2$ ペアしか変えないので，スコアは $a+b-2$ 以上です．
$a,b$ がともに正ならば，00, 11 の間のところを境界として操作することでこれを達成できます．

$a>0,b=0$ のような場合だけが問題です．この場合，reverse 境界を

- 00 の間
- 01 の間
- 区間の端 #0 の間
- 区間の端 #1 の間

みたいに場合分けして考えると，端に $1$ がある場合だけスコアを減らせることが分かります．
