# M - 秘密の数列と分岐するノート

- 問題: [atcoder/awc0100/m](https://atcoder.jp/contests/awc0100/tasks/awc0100_m)
- 問題名: M - 秘密の数列と分岐するノート
- tags: `Rollback_UnionFind` `ポテンシャル付きUnionFind`
- difficulty: `5`
- id: `atcoder/awc0100/m`
- logged_at: `2026-06-28`

## memo

「版は木状に分岐していきます」の指す通りの木を作り，木を dfs traversal しながら各版での答を求めていきます．

すると，「条件の追加（追加可能性の判定）」「rollback」ができればよいということになります．

古くに追加された条件を適当順に削除する一般的には難しいのですが，rollback は簡単です．
その間に行われた配列 update をすべて覚えておき，ひとつずつ戻していくようにすればよいです．

今回は，ポテンシャル付き UnionFind を持って条件の追加や rollback に対応すればよいです．
