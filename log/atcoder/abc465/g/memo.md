# G - Sum of Mex of Mod of Linear

- 問題: [atcoder/abc465/g](https://atcoder.jp/contests/abc465/tasks/abc465_g)
- 問題名: G - Sum of Mex of Mod of Linear
- difficulty: `5`
- tags: `差分更新` `実装`
- id: `atcoder/abc465/g`
- logged_at: `2026-07-04`

## memo

基本的には実装問題です．やや大変．

ポイントとして，ある $i$ に対して $Ck+A_i\equiv 0$ となるような $k$ だけ考慮すればよいです．
それ以外のところでは mex は $0$ になるからです．

各 $x$ に対して，

- $cnt[x]$： $Ck+x\equiv 0$ となる $k$ の個数．
- $mex[x]$： $Ck+x\equiv 0$ となるような $k$ 時点での mex．
- $ans[x]$： $cnt[x]\times ans[x]$

として， $ANS=\sum_x ans[x]$ を管理します．

$x$ が削除されて $y$ が追加されると，だいたい $x$ 自身，または $mex[y]=x-y$ であったような $y$ が更新対象となります．

$cnt[x]$ や $cnt[x] \times x$ に対する累積和テーブルを用意しておくことで差分更新を高速に行えます．

ある時刻の $A_i$ として現れうる $x$，およびそのような $x$ に対する $x+1$ を基準として座標圧縮をしてこれを実装しました．
