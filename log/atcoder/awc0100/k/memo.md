# K - 商店街の区画選び

- 問題: [atcoder/awc0100/k](https://atcoder.jp/contests/awc0100/tasks/awc0100_k)
- 問題名: K - 商店街の区画選び
- tags: `平方分割` `KD_tree`
- difficulty: `4`
- id: `atcoder/awc0100/k`
- logged_at: `2026-06-28`

## memo

まず，タイプ $2$ のクエリは，choice i： $[i,i+K)$ として， $1\leq i \leq N-K+1$ を選ぶ問題だとします．
$n=N-K+1$ として， $n$ 種の選択の情報を管理します．

$i$ 番目の選択肢の合計賃料を $B_i$ として，合計駐車スペース数を $D_i$ とでもすれば，

- $B_i$ に対する区間加算
- $D_i\geq X_j$ であるような $i$ に対する $B_i$ の最小値クエリ

という形になります．


ひとつの見方は $2$ 次元矩形クエリで，点 $(i, D_i)$ を考えると， $x$ 方向の区間加算と $y$ 方向の区間 max が来ます．
矩形クエリで加算，max のような処理は通常 $o((N+Q)^{1.5})$ のような計算量にするのは難しいです．

https://drive.google.com/file/d/1bSjYiA-nSsHzBbCnLq1GeTpRzs2Ucm0q/view

平方分割で， $X_i$ の範囲が小さいことを使って $1.5$ 乗計算量．平方分割は TL バトルになりやすいので，二分探索 log が落とせるかなどは慎重に吟味するとよいです．

しかし私は矩形に対して加算，max のできる KD tree を使いました．KD tree は列の平方分割に比べて定数倍が大きいことも多いんですが，大丈夫でした．
