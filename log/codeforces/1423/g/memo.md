# G. Growing flowers

- 問題: [codeforces/1423/g](https://codeforces.com/contest/1423/problem/G)
- 問題名: G. Growing flowers
- difficulty: `7`
- tags: `区間種類数` `実装`
- id: `codeforces/1423/g`
- logged_at: `2026-07-14`

## memo

区間種類数なので，まず

prev[i] := max j such that A[j]=A[i]

を考えます．ペア (prev[i],i) 全体を考えると，区間定数代入クエリは，償却 $O(N+Q)$ 回の追加削除になります．

これらのペアの追加削除を行いながら，次に各 $K$ に対する 

$ANS[K]$

がどのようになるかを考えます．すると，固定された $(i,j)$ の $ANS[K]$ への寄与は， $K$ の区間ごとに $K$ の $1$ 次関数になることが分かります．

つまり $ANS[K]=a[K]\cdot K + b[K]$ となる配列 $a,b$ に対する区間加算などによって表すことができます．
