# E. lce4113 and Security Game

- 問題: [codeforces/2246/e](https://codeforces.com/contest/2246/problem/E)
- 問題名: E. lce4113 and Security Game
- difficulty: `4`
- tags: `インタラクティブ`
- id: `codeforces/2246/e`
- logged_at: `2026-07-13`

## memo

まず adaptive な以上，bit 同士の区別はなくて， $x$ は popcnt 分の情報しかありません．

$(m_0,m_1)$ については $(m_0\oplus c, m_1\oplus c)$ を送るのと同じことになるので， $m_0=0$ として考えればよいです．

$o(v,x)=x$ のとき以外は簡単です． $o(v,x)$ と $x$ が不一致であるような桁を見れば $v$ の $k$ 桁目が決まるので， $m_1=2^k$ を送ればよいです．

$o(v,x)=x$ のときだけが問題です．

$x=1$ で解けます．難しいケースというのは，「 $v$ は $0$ または奇数」の場合です．

このあと $m=m_1$ を奇数から乱択します．このとき，

- $0\oplus 0$
- $0\oplus m$
- $odd\oplus 0$
- $odd\oplus m$

について， $\oplus$ されたものが区別できればよいです．

$odd \oplus 0$, $odd \oplus m$ がそれぞれ偶然に $m,0$ になってしまうと判定失敗で，それが起こらないと信じると判定成功します．
判定失敗は $m$ を乱択したとき $1/2^{29}$ 程度です．
