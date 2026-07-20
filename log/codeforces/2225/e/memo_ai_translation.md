> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. Covering Points with Circles

- Problem: [codeforces/2225/e](https://codeforces.com/contest/2225/problem/E)
- Problem Name: E. Covering Points with Circles
- difficulty: `4`
- tags: `乱択アルゴリズム` `最密充填` `幾何構築`
- tag_en: `randomized algorithm` `densest packing` `geometric construction`
- id: `codeforces/2225/e`
- logged_at: `2026-07-01`

## memo

Use a densest-packing-like arrangement. Let $H$ be about $\sqrt{3}R$, and place points at $(iR, jH)$ with $i+j\equiv 0\pmod{2}$.

If we shift this randomly, then each point is covered with probability about $90.6\%$. We randomize the shift amount and repeat until the target of at least $89\%$ is reached.

Since the shift amount is an integer, I did not verify whether the probability under this conditioning is really that value, but I believed that the problem setting of $R\geq 100$ is there for that purpose.
