# G - 硬貨

- 問題: [atcoder/fps-24/fps_24_g](https://atcoder.jp/contests/fps-24/tasks/fps_24_g)
- 問題名: G - 硬貨
- difficulty: `4`
- tags: `戻すdp`
- id: `atcoder/fps-24/fps_24_g`
- logged_at: `2026-07-02`

## memo

ちょうど $n$ 円を払う方法の数え上げ $\dp[n]$ という dp テーブル（ $0\leq n\leq N$）を考えてある硬貨の追加・削除を行えればよいです．

削除が少し直感的に処理しにくいですが，FPS で考えれば追加は単に $\frac{1}{1-x^a}$ をかけることなので，削除は $(1-x^a)$ をかけることを実装すればよいです．
