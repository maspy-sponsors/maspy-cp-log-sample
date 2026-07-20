> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# F. String Cutting

- Problem: [codeforces/2225/f](https://codeforces.com/contest/2225/problem/F)
- Problem Name: F. String Cutting
- difficulty: `4`
- tags: `文字列` `文字列比較`
- tag_en: `string` `string comparison`
- id: `codeforces/2225/f`
- logged_at: `2026-07-02`

## memo

Actually, it is enough to look only at the patterns that are split into exactly $K$ pieces.

Fix the target $ANS$, and take one optimal solution.
If we represent the split as a `01` sequence by treating values less than $ANS$ as `0` and values greater than or equal to $ANS$ as `1`, then there are at least $K$ pieces in total, and the number of `0`s is at most $K-1$.

While the whole sequence has at least $K+1$ pieces, perform the operation “replace `10` or `11` with `1`”.

If after exhausting this process it still has at least $K+1$ pieces, then it is of the type `00000001`. In this case, combine `00` arbitrarily (it will be replaced by `0` or `1`).

With this, we can transform it into a length-$K$ `01` sequence that contains `1`s. The case that is problematic is when $K=1$ and the type becomes `01`, but when $K=1$ there must not be any `0`s, so we do not need to consider this either.

Therefore, we consider the problem of splitting into exactly $K$ pieces. Then the objective becomes maximizing the `max`. So it becomes maximizing “one arbitrarily chosen piece after splitting into $K$ pieces”.

After that, fix $L$ and consider solutions of the form $[L,R)$. Among the ones that can be split into exactly $K$ pieces, take the longest one as a candidate for ANS.

Since the number of candidate substrings becomes $O(N)$, we can then compare them using a suffix array, etc.
