# B - Window Records

- 問題: [atcoder/awtf2026algo/b](https://atcoder.jp/contests/awtf2026algo/tasks/awtf2026algo_b)
- 問題名: B - Window Records
- difficulty: `7`
- tags: `判定問題解法でdp`
- id: `atcoder/awtf2026algo/b`
- logged_at: `2026-07-10`

## memo

まずは $p$ から $x$ を計算する方法を確認します．

列の後ろ側から処理します．これは以下の要領でできます．

- 各時点での record からなる列を管理する
- 手前に $p_i$ を追加するとき，それ以下の record を prefix 側から削除する
- 保持している record の末尾が size $N$ の windown の外側にあるならば，それを削除する
- record として手前に $i$ を追加する

この動きを踏まえた上で，次に，列 $x$ に対する判定問題を考えます．

同じ $x$ について，それを実現するような record 列の動き方が複数ありえます．これについて，pop_font 側と pop_back 側（こっちは高々ひとつ）の $2$ 択の自由度が残ります．これは実は，隙あらば pop_back 側を優先することが貪欲な選択であることがいえます．pop_front 側は後からでも好きなタイミングでできる一方，pop_back はあるステップでちょうどそのインデックス位置に record が残っていることが強制されるからです．

このように pop_back 側を優先するようにすると，まず判定問題が $O(N)$ 時間で解けるようになります．この際に現れる状態が $polynomial(N)$ 状態で書けるため，その判定問題の解法をそのまま dp にすればよいです．

具体的には，インデックス $N$ 以下の要素数および，インデックス $N+1$ 以上部分から pop_front, pop_back された回数の組を状態とすればよいです．
