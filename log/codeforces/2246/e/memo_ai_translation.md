> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.

# E. lce4113 and Security Game

- Problem: [codeforces/2246/e](https://codeforces.com/contest/2246/problem/E)
- Problem Name: E. lce4113 and Security Game
- difficulty: `4`
- tags: `インタラクティブ`
- tag_en: `interactive`
- id: `codeforces/2246/e`
- logged_at: `2026-07-13`

## memo

Since it is adaptive, there is no distinction between bits; `x` only contains information proportional to `popcnt`.

For `(m_0, m_1)`, sending `(m_0 \oplus c, m_1 \oplus c)` is equivalent, so we may assume `m_0 = 0`.

Cases other than when `o(v, x) = x` are easy. By looking at a digit where `o(v, x)` and `x` differ, the `k`-th digit of `v` is determined, so it is enough to send `m_1 = 2^k`.

Only the case `o(v, x) = x` is problematic.

It can be solved with `x = 1`. The difficult case is when `v` is `0` or odd.

After that, choose `m = m_1` uniformly at random from odd numbers. At this point, it is enough to be able to distinguish the following four values after `\oplus`:

- `0 \oplus 0`
- `0 \oplus m`
- `odd \oplus 0`
- `odd \oplus m`

If `odd \oplus 0` and `odd \oplus m` accidentally become `m` and `0`, respectively, then the判定 fails; if that does not happen, the判定 succeeds.

When `m` is chosen at random, the probability of 判定 failure is about `1/2^{29}`.
