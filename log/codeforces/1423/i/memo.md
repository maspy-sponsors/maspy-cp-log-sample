# I. Lookup Tables

- 問題: [codeforces/1423/i](https://codeforces.com/contest/1423/problem/I)
- 問題名: I. Lookup Tables
- difficulty: `5`
- tags: []
- id: `codeforces/1423/i`
- logged_at: `2026-07-14`

## memo

計算量を問わなければ，

$$a_i AND b_j = v$$

の形の条件が大量に与えられているだけです．こういうのは $a_i,b_j\supset v$ という条件から必要最小限の bit だけを持たせた $a, b$ を求めて，条件を判定すればよいです．

これを区間の上位・下位ビットについて行う必要があります．前半パートは双対セグメント木でできます．後半パートも，上位ビットの先頭と末尾の端数処理だけ適切にすれば，セグメント木でできます．
