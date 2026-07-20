# 14F. Connected Interval Prefixes

- 問題: [repovive/14/f](https://repovive.com/contests/14/problems/F)
- 問題名: 14F. Connected Interval Prefixes
- difficulty: `7`
- tags: `区間dp` `区間を置いていくdp`
- id: `repovive/14/f`
- logged_at: `2026-06-30`

## memo

valid な permutation について，和集合区間が増大するところに注目します．

$$
I_1\subsetneq I_2\subsetneq \cdots \subsetneq I_k =[1,N]
$$

とします． $I_j$ 内にある入力区間の個数を $C_j$ とします．また，増大するところについてはどの区間を使って増大したかも固定します．

すると，この増大方法を固定した場合の数え上げが

$$
(N-1)!\cdot \prod_{j=1}^{k-1}\frac{1}{N-C_j}
$$

とかになります．熱心な式変形をして導出しましたが，次のような解釈が可能です．

まず，最初に選ぶ区間が決まっている状態 $(N-1)!$ 通りから考えます．そこから

- $N-C_1$ 個の区間の中では $I_2$ に増大させるときに使う区間が先頭，
- $N-C_2$ 個の区間の中では $I_3$ に増大させるときに使う区間が先頭，
- $\vdots$

というような条件があります．これはなんと独立です．後半の条件を満たす列に小さい区間を挿入することを考えるとよいです．
