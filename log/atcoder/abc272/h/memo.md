# Ex - Flipping Coins 2

- 問題: [atcoder/abc272/h](https://atcoder.jp/contests/abc272/tasks/abc272_h)
- 問題名: Ex - Flipping Coins 2
- difficulty: `7`
- tags: `固有関数` `rook_polynomial` `newton_basis` `下降べき`
- id: `atcoder/abc272/h`
- logged_at: `2026-07-08`

## memo

algorithm lectures で解説しました．
コンテスト当時は，公式解説の謎変数変換（なぜか $e^x$ 倍を考えると綺麗になる）が上手く解釈できなかったのですが，
現在はこのように理解しています．

https://info.atcoder.jp/entry/algorithm_lectures/eigenfunction

----

そもそも rook polynomial という有名問題として理解できます．
包除原理の適用先は，各 $k$ に対して，rook をヤング図形に干渉しないように $k$ 個置く問題です．
$k$ 個置く方法を $r_k$ として， $\sum r_kx^k$ をこのヤング図形の rook polynomial といいます．

列数を $A_i$ で昇順とすると，各行に余分な列を $x$ 個追加してから「全行に rook を置く方法」を数えることで，等式

$\prod_i (x + A_i - i) = \sum r_i (x)_i$

ここで $(x)_i$ は下降冪です．したがって $r_i$ を求めるには左辺を Newton Basis に変換すればよいです．

また解説の方法は，次のような下降べきと EGF の関係を利用していると解釈できます．

- $f(x) = \sum_{i=0}^n a_i (x)_i$ とする．
- $g(x) = \sum_{i=0}^n a_i x ^ i$ とする．
- このとき $e^xg(x) = \sum_{i=0}^{\infty} \frac{f(i)}{i!}x^i$

つまり $f(x)$ が与えられて $g(x)$ を求めたいのですが，これを $f$ を多点評価して $e^xg(x)$ を求めることで $g(x)$ を求めています．
