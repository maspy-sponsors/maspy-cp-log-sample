> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# A. A Number Between Two Others

- Problem: [codeforces/2225/a](https://codeforces.com/contest/2225/problem/A)
- Problem Name: A. A Number Between Two Others
- difficulty: `2`
- tags: `整数論計算量`
- tag_en: `integer theory` `complexity`
- id: `codeforces/2225/a`
- logged_at: `2026-07-01`

## memo

Since we are only interested in multiples of $x$, if we divide everything by $x$, the problem becomes finding something that is not a divisor of $y$.

If we search up to $1,2,\ldots,k$ and still do not find one, that means $y$ is a multiple of their least common multiple; however, since the least common multiple is on the order of $\exp(k(1+o(1)))$,

https://info.atcoder.jp/entry/algorithm_lectures/prime_related_complexity

taking this into account, the brute-force trial solution is fast enough.
