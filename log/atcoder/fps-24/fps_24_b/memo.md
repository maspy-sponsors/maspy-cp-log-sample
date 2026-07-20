# B - 整数の組

- 問題: [atcoder/fps-24/fps_24_b](https://atcoder.jp/contests/fps-24/tasks/fps_24_b)
- 問題名: B - 整数の組
- difficulty: `3`
- tags: `C-recursive`
- id: `atcoder/fps-24/fps_24_b`
- logged_at: `2026-07-02`

## memo

$[x^N](1+x)\cdot (1+x^2)\cdot \frac{1}{1-x^2}\cdot \frac{1}{1-x^3}$ と立式できます．

有理式の係数を求める問題（線形漸化式の $K$ 項目を求める問題）で，Bostan-Mori 法などで解けます．
$O(\log N)$ 時間．
