> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# O - 円環石板の結合

- Problem: [atcoder/awc0100/o](https://atcoder.jp/contests/awc0100/tasks/awc0100_o)
- Problem Name: O - 円環石板の結合
- difficulty: `6`
- tags: `monge` `Knuth_Yao_SpeedUp`
- tag_en: `monge` `Knuth_Yao_SpeedUp`
- id: `atcoder/awc0100/o`
- logged_at: `2026-06-28`

## memo

This is also almost exactly the same as a well-known classic problem. The next problem has an explanation on the problem page.

https://atcoder.jp/contests/atc002/tasks/atc002_c

Use the $O(n^2)$ solution from the explanation. This is called Knuth-Yao SpeedUp. With this, you can obtain the optimal solution for each interval.

This time it is circular, but if you extend it to length $2n$ and take the minimum over the solutions for $[i,i+n)$, that is enough.
