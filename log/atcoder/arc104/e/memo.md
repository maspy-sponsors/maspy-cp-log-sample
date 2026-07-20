# E - Random LIS

- 問題: [atcoder/arc104/e](https://atcoder.jp/contests/arc104/tasks/arc104_e)
- 問題名: E - Random LIS
- difficulty: `5`
- tags: `N<=6` `lis数え上げ`
- id: `atcoder/arc104/e`
- logged_at: `2026-07-03`

## memo

とにかく計算量が $\max A_i$ に依存しなければだいたい大丈夫だという問題です．

まず LIS を定めるために値の順序 $N!$ 通りを決めます．この際，同じ値同士では右に書かれている順序を先にするというタイブレイクルールを採用するとして，LIS が正しく求まるようにします．

そのあと，それぞれの項をどの座圧区間から選ぶかを決めます．

最大 $720\times 462$ 通りの問題に分けて，それぞれを $O(N)$ 時間で数えます．
