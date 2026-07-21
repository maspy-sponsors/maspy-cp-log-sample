# Terms of Use

This repository is privately shared with sponsors on eligible GitHub Sponsors tiers of $3 per month or more.

Therefore, sharing, reposting, redistributing, or otherwise providing the whole repository, or a large number of `main.cpp` / `memo.md` / `index` files, to third parties is not permitted.

Paid sponsors may copy source code and explanations for their own private use.

If you want to share the contents of this repository within a group, or use them for educational materials, commercial services, articles, lectures, books, AI training data, or similar purposes, please contact me in advance.

Possible contact methods:

* X (Twitter): @maspy_stars
* Codeforces: maspy
* E-mail: [maspypy@gmail.com](mailto:maspypy@gmail.com)

# Repository Contents

This repository is a log of maspy's competitive programming submissions and solution notes.

For each problem, this repository stores the submitted source file `main.cpp` and a short solution note `memo.md`. Many notes are only a few lines long.

Some problems have tags when I think they are useful for finding typical techniques, related problems, or practice problems in a specific area.

This repository originally started as a personal record for my own use, but I am making it available on a limited basis because I believe others may also find it useful. I will continue adding not only problems that I solve from now on, but also problems that I solved in the past, as I organize my existing submissions and notes.

For a while, I plan to add roughly 200 to 1000 problems per month. Actual monthly additions are available in [`index/stats.md`](index/stats.md). The pace may vary depending on circumstances.

## main.cpp

`main.cpp` is the file I wrote when solving the problem. However, it usually does not compile as-is.

To make it submittable, you need my personal competitive programming library. The libraries included from `main.cpp` are in the following repository:

https://github.com/maspypy/library

You can use the following expander to recursively expand the includes into a single source file:

https://github.com/maspypy/library/blob/main/expander.py

However, if you only want to read the implementation for reference, this expansion step is usually unnecessary.

Also, the library interface may have changed since the time the solution was written. Therefore, old `main.cpp` files may not be compatible with the latest version of my personal library.

## memo.md

`memo.md` is a short solution note.

I do not aim to provide explanations that are more detailed or more beginner-friendly than official editorials.

The explanations are mainly intended for intermediate to advanced users. Some notes contain careful proofs, but this is more likely for harder problems.

## memo_ai_translation.md

Some problems may also have `memo_ai_translation.md`.

This is a fully machine-generated English translation of `memo.md`. It is provided only as a reference for non-Japanese readers.

The Japanese `memo.md` is the original and authoritative version. The AI translation may contain mistakes.

Each `memo_ai_translation.md` starts with the following notice:

```md
> This file is a fully machine-generated translation of `memo.md`.
> The Japanese `memo.md` is the original and authoritative version.
> This translation may contain mistakes.
```

## difficulty

Difficulty is rated on a 10-level scale from `1` to `10`.

A very rough guideline is that multiplying this value by about 120 to 180 gives something comparable to an AtCoder point value.

This rating is not very rigorous. The scale may vary over time. It also does not necessarily reflect the contest author's difficulty estimate or the contest standings. It can be strongly affected by whether I personally struggled with the problem or solved it quickly.

## tag

Some problems have tags. These are intended to make it easier to find related problems or collect practice problems for a specific topic.

Some problems have no tags. In many cases, if I do not come up with useful tags within about 10 seconds, I leave the tag list empty.

Tags are not a strict classification system. They may contain inconsistencies, and better tag names may be chosen later.

## tag_en

Some translated notes may contain `tag_en`.

This is a machine-generated English translation of the Japanese tags. It is only reference information and may contain inconsistencies or mistranslations.

# index

The `index/` directory contains generated indexes for finding problems.

* [`index/stats.md`](index/stats.md): problem counts, monthly additions, and difficulty distribution
* [`index/recent.md`](index/recent.md): recently added problems
* [`index/difficulty.md`](index/difficulty.md): difficulty distribution and D7-D10 problems
* [`index/tags.md`](index/tags.md): problems grouped by tags
* [`index/includes.md`](index/includes.md): problems grouped by direct includes in `main.cpp`
* [`index/sites.md`](index/sites.md): site / contest navigation
* [`index/contests/`](index/contests/): contest-level indexes
* [`index/problems.tsv`](index/problems.tsv): machine-readable list of all problems

`index/problems.tsv` contains the following columns:

```text
id
site
contest
problem
title
difficulty
tags
includes
logged_at
memo_path
source_path
url
summary
```

This file is useful if you want to search or aggregate the data with `grep`, scripts, or spreadsheet software.

# Intended Use Cases

## Reading explanations for contests or problems you solved

If I have solved the same problem, this repository may help.

However, the explanations are intended for intermediate to advanced users. I do not aim to provide explanations that are more detailed than official editorials, and this repository is probably not useful if a beginner is looking for a very gentle explanation.

Compared with official editorials, possible advantages are that the note may contain a different point of view, and that the explanation is in Japanese.

For non-Japanese readers, `memo_ai_translation.md` may help, but it is a machine translation and may contain mistakes.

## Reading implementations

The implementations may be useful as references.

However, they are usually saved as-is from the contest or from the first time I solved the problem. I do not clean up the logic or improve readability for readers.

On the other hand, this means they may show what kind of implementation I actually write in a contest-like setting. Also, because the library includes are not expanded, it may be easier to read only the part that I actually wrote during the contest compared with reading a full submitted source file.

## Finding Problems by Difficulty or Tags

For common beginner-level topics, there are probably many better curated resources available elsewhere.

On the other hand, `index/difficulty.md` may be useful when looking for harder problems, while `index/tags.md` may help when searching for rarely covered topics or typical techniques for intermediate to advanced users.

## Finding problems by library usage

`index/includes.md` lists problems by direct includes in `main.cpp`.

For example, you can find problems that directly use:

```cpp
#include "ds/segtree/segtree.hpp"
```

or:

```cpp
#include "graph/tree_dp/rerooting_dp.hpp"
```

This may be useful when looking for real use cases of a specific library, or when looking for practice problems involving uncommon implementation patterns.

However, this index only considers includes written directly in `main.cpp`. It does not include indirect dependencies included from inside the library.

For frequently used libraries, `index/includes.md` may show only part of the list. The complete list is kept in the `includes` column of `index/problems.tsv`.
