# F. Paths on a Grid

- 問題: [codeforces/2247/f](https://codeforces.com/contest/2247/problem/F)
- 問題名: F. Paths on a Grid
- difficulty: `5`
- tags: `dominator_tree` `ハッシュ`
- id: `codeforces/2247/f`
- logged_at: `2026-07-19`

## memo

「 $A$ を通るならば $B$ も通る，逆も然り」という関係のときに同値．
という関係による同値類分解を求めよということです．

これは， $s$ を根とする dominator tree と， $t$ を根とする dominator tree を作れば，

- $u$ は木 $T_A$ における $v$ の祖先
- $v$ は木 $T_B$ における $u$ の祖先

の両方が成り立つことと同値です．

あとはこの関係で同値類分解すればよいです．

- $T_A$ において，先祖側から dominator 関係 $a\to b\to c$ がある
- $a,c$ は同じ同値類に属する

を仮定します．パス $P$ について，

- $c\in P\implies b\in P\implies a\in P$
- $a\in P\iff c\in P$

ということで，このとき $a\in P\iff b\in P$ および $b\in P\iff c\in P$ が示せます．
すると結局， $a,c$ の同値関係は $a,b$ の関係と $b,c$ の関係から生成できます．

したがって，同値関係は $T_A$ における直接の親子から生成できます．

----

別解情報

頂点に重み $a_v$ をつけて，パスの重みを通るセルの重みの総積とします．
ある頂点に対して，それを通るパス重みの総和を考えます．

$a_v$ を不定元と見たときにこの総和が同じであるものが同じ連結成分です．
$a_v$ を乱数にしてこれをやればよいです．
