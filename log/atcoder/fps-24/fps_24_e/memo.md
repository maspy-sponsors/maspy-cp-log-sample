# E - 数列 3

- 問題: [atcoder/fps-24/fps_24_e](https://atcoder.jp/contests/fps-24/tasks/fps_24_e)
- 問題名: E - 数列 3
- difficulty: `4`
- tags: `EGF`
- id: `atcoder/fps-24/fps_24_e`
- logged_at: `2026-07-02`

## memo

出現回数を $c_1,c_2,\ldots$ とすると，適切な範囲で $\frac{N!}{c_1!\cdots c_M!}$ を足し合わせる問題になります．適切な範囲とは， $\sum c_i=M$ かつ $0\leq c_i\leq i$ で，これを考慮すると答えは次のように立式できます．

$$N!\cdot [x^M]\prod_i \sum_{c=0}^i\frac{x^c}{c!}$$
