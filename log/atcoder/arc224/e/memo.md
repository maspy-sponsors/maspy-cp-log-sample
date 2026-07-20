# E - ABC|AB|A

- 問題: [atcoder/arc224/e](https://atcoder.jp/contests/arc224/tasks/arc224_e)
- 問題名: E - ABC|AB|A
- difficulty: `3`
- tags: []
- id: `atcoder/arc224/e`
- logged_at: `2026-07-12`

## memo

ABC があれば消す，それがないときに AB があれば消す，という種の貪欲でよいです．

より簡潔に手前から $1$ 文字ずつ消すこともできそうですが，「AB」まで見ても次の文字が何であるかが分からないなどがあって少しややこしいです．

reverse すると，手前から見て A が来た瞬間に，CBA, BA, A のうち最も長いものを消すという形で 1 文字ずつ処理しやすくなります．
