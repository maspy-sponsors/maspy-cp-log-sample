# E. Kevin and And

- 問題: [codeforces/2061/e](https://codeforces.com/contest/2061/problem/E)
- 問題名: E. Kevin and And
- difficulty: `4`
- tags: `min_plus_convolution` `凸性の証明`
- id: `codeforces/2061/e`
- logged_at: `2026-07-19`

## memo

各 $i$ に対して，操作回数ごとの最適解を求めておきます．これは $O(2^M)$ 時間かけて求めます．
これが下凸になる，というのがポイントです．証明は結構珍しい気がします．最終的な解法は，下凸関数をたくさん min-plus 畳み込みするだけです．

凸性の証明をします． $a \in A$ を固定します．

- $B$ の部分集合 $S$ について， $f(S)$ を， $S$ の各要素と AND をとった値とします．
- $F(k)$ を $|S|=k$ となる $S$ にわたる $f(S)$ の最小値とします．
- $2F(k+1)\leq F(k)+F(k+2)$ を示します．
- $f(S)=F(k),f(T)=F(k+2)$ として $2F(k+1)\leq f(S)+f(T)$ を示せばよいです．

$f(S)>f(T)$ として示せばよく， $f(S),f(T)$ で違いの生じる bit のうち最上位のものをとります．
この違いの原因となる要素を $b\in B$ とすれば，

$$
f(S)+f(T)\geq f(S\cup \{b\})+f(S\cup \{b\})
$$

が示せます．
