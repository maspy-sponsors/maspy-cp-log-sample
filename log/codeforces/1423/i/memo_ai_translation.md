> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# I. Lookup Tables

- Problem: [codeforces/1423/i](https://codeforces.com/contest/1423/problem/I)
- Problem Name: I. Lookup Tables
- difficulty: `5`
- tags: []
- tag_en: []
- id: `codeforces/1423/i`
- logged_at: `2026-07-14`

## memo

If we ignore the time complexity,

we are simply given a large number of conditions of the form

$$a_i AND b_j = v$$

For this kind of thing, from the condition $a_i,b_j\supset v$, we can find $a, b$ that have only the minimum necessary bits, and then check the conditions.

This needs to be done for the upper and lower bits of intervals. The first half part can be done with a dual segment tree. The second half part can also be done with a segment tree, as long as we handle the endpoints and remainders of the upper bits appropriately.
