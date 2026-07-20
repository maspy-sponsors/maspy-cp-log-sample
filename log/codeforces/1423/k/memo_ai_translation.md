> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# K. Lonely Numbers

- Problem: [codeforces/1423/k](https://codeforces.com/contest/1423/problem/K)
- Problem Name: K. Lonely Numbers
- difficulty: `3`
- tags: []
- tag_en: []
- id: `codeforces/1423/k`
- logged_at: `2026-07-14`

## memo

Composite numbers are not lonely. In fact, if $a=px$ with $2\leq p, x$, then letting $b=p(x-1)$ makes a triangle成立.

Therefore, it is enough to consider prime numbers $p$ as candidates. The possible $\gcd$ values are only $1$ or $p$, and considering these cases shows that $p$ stops being lonely only in the case of $(p,p^2)$. From here, the answer is the number of primes in an appropriate interval.
