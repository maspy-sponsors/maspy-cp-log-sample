# C - Ascending Labels

- 問題: [atcoder/arc224/c](https://atcoder.jp/contests/arc224/tasks/arc224_c)
- 問題名: C - Ascending Labels
- difficulty: `2`
- tags: `DFS木`
- id: `atcoder/arc224/c`
- logged_at: `2026-07-12`

## memo

DFS 木が条件を満たします．木辺または後退辺（この場合多重辺がないので $2$ 個以上祖先に進んだところへ行く）しかないからです．

はじめ BFS 木を作ってしまったのですが，「ちょうど $1$ つ」を見落としていました．
