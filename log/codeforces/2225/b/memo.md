# B. Alternating String

- 問題: [codeforces/2225/b](https://codeforces.com/contest/2225/problem/B)
- 問題名: B. Alternating String
- difficulty: `3`
- tags: []
- id: `codeforces/2225/b`
- logged_at: `2026-07-01`

## memo

この問題文の書き方で "you are allowed to do it, but you don't have to do it" がカッコ書きで補足されているのが気づきにくすぎる．

作れる文字列とそのときの操作パターンを考えると，操作位置は両端や $S[i] != S[i+1]$ となる場所の関係者だけを候補としておけばよいことが分かります．そのような個数が多すぎると無理，そうでない場合そういう場所を候補として全探索しました．
