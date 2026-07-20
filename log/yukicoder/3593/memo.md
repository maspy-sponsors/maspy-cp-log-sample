# No.3593 I Love Sudoku

- 問題: [yukicoder/3593](https://yukicoder.me/problems/no/3593)
- 問題名: No.3593 I Love Sudoku
- difficulty: `8`
- tags: `線形代数` `構築` `群` `数独`
- id: `yukicoder/3593`
- logged_at: `2026-07-17`

## memo

$9$ 元群 $G$ を用意します．

$G$ 上の群環を考えて，

$a = \sum a_gX^g, b = \sum b_gX^g$ とします．
まず畳み込み $c = \sum_c_g X^g$ として， $a,b,c$ がそれぞれ順列となるものを探索します．

これらを行列と見なせば，行条件と列条件は自動的に満たされます．

ブロック条件は，これらに適当な置換行列を作用させることで調整します．

- $A'=PAQ$
- $B'=Q^{-1}BR$
- $C'=PCR$

のようにしてブロック条件を狙います．


$$G = \mathbb{Z}/3\mathbb{Z}\times \mathbb{Z}/3\mathbb{Z}$$

ととれば上手くいきました．

はじめ， $G = \mathbb{Z}/9\mathbb{Z}$ に相当するものを（群の言葉を使わずに）考えていたのですが，そこから群の言葉で整理して，方針転換してこうなりました．
