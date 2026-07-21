Japanese: [README.md](README.md)

# Terms of Use

This repository is privately shared with sponsors on eligible GitHub Sponsors tiers of $3 per month or more.

Therefore, sharing, reposting, redistributing, or otherwise providing the whole repository, or a large number of `main.cpp` / `memo.md` / `index` files, to third parties is not permitted.

Eligible sponsors may copy source code and explanations for their own private use.

If you want to share the contents of this repository within a group, or use them for educational materials, commercial services, articles, lectures, books, AI training data, or similar purposes, please contact me in advance.

Possible contact methods:

- X (Twitter): @maspy_stars
- Codeforces: maspy
- E-mail: [maspypy@gmail.com](mailto:maspypy@gmail.com)

# Repository Contents

This repository is a log of maspy's competitive programming submissions and solution notes.

For each problem, this repository stores the submitted source file `main.cpp` and a short solution note `memo.md`. Many notes are only a few lines long.
Some problems have tags when I think they are useful for finding typical techniques, related problems, or practice problems in a specific area.

This repository originally started as a personal record for my own use, but I am making it available on a limited basis because I believe others may also find it useful. I will continue adding not only problems that I solve from now on, but also problems that I solved in the past, as I organize my existing submissions and notes.

For a while, I plan to add roughly 200 to 1000 problems per month. The pace may vary depending on circumstances. Actual monthly additions are available in [`index/stats.md`](index/stats.md).

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

I do not aim to provide explanations that are more detailed than official editorials. Because the notes are based on solutions I came up with myself, some of them may be more roundabout or contain more unnecessary steps than the official editorial.

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

A very rough guideline is that multiplying the rating by about 150, or roughly 120 to 180, gives something comparable to an AtCoder point value.

This rating is not very rigorous. The scale may vary somewhat over time. It also does not reflect the contest author's difficulty estimate or the contest standings. It can be strongly affected by whether I personally happened to struggle with a problem or happened to solve it quickly.

## tag

Some problems have tags. These are intended to make it easier to find related problems or collect practice problems for a specific topic.

Some problems have no tags. In many cases, if I do not come up with useful tags within about 10 seconds, I leave the tag list empty.

The primary purpose of the tags is my own searching. They are therefore not especially precise as a classification system for general users, and general-purpose tagging sites are usually more comprehensive for common topics.

On the other hand, when adding tags, I try to make it easier to find related problems for topics that appear very rarely. The tags may therefore be useful for discovering an unusual perspective on a problem, or for finding related problems on topics that are difficult to cover without solving many problems across multiple sites.

Tags may contain naming inconsistencies, and better tag names may be chosen later.

## tag_en

Some translated notes may contain `tag_en`.

This is a machine-generated English translation of the Japanese tags. It is only reference information and may contain inconsistencies or mistranslations.

# index

The `index/` directory contains generated indexes for finding problems.

- [`index/stats.md`](index/stats.md): problem counts, monthly additions, and difficulty distribution
- [`index/recent.md`](index/recent.md): recently added problems
- [`index/difficulty.md`](index/difficulty.md): difficulty distribution and D7-D10 problems
- [`index/tags.md`](index/tags.md): problems grouped by tags
- [`index/includes.md`](index/includes.md): problems grouped by direct includes in `main.cpp`
- [`index/sites.md`](index/sites.md): site / contest navigation
- [`index/contests/`](index/contests/): contest-level indexes
- [`index/problems.tsv`](index/problems.tsv): machine-readable list of all problems

`index/problems.tsv` contains the problem ID, site, contest, problem, title, difficulty, tags, includes, logged_at, memo_path, source_path, URL, and summary.

This file is useful for searching or aggregating the data with `grep`, scripts, or spreadsheet software.

To browse problems from a specific site or contest together, use [`index/sites.md`](index/sites.md) or [`index/contests/`](index/contests/).

# Intended Use Cases

## Reading explanations for contests you participated in or problems you solved

If the same problem is included in this repository, you can check the key ideas of the solution in `memo.md`. As a general rule, I also plan to add notes for problems I solve in future contests I participate in.

However, the explanations are intended for intermediate to advanced users, and many notes do not explain the entire solution or all of its details.
I do not aim to provide explanations that are more detailed than official editorials, and this repository is often not useful for beginners looking for a gentle explanation.

Compared with official editorials, possible advantages include:

- For contests such as Codeforces Div. 2, when the difficulty allows, solution notes are often added relatively soon after the contest ends (sometimes immediately afterward)
- Depending on when the official editorial is published, a solution note may be available earlier
- A solution note may present a different perspective from the official editorial

For non-Japanese readers, `memo_ai_translation.md` may help. However, it is a fully machine-generated translation, the Japanese `memo.md` is the original and authoritative version, and the translation may contain mistakes.

## Reading implementations

For each problem, `main.cpp` shows the implementation I wrote when solving it.

Many `main.cpp` files are saved as-is from the contest or from the first time I solved the problem. As a rule, I do not remove unnecessary logic or improve readability for readers.

On the other hand, some implementations were cleaned up after the contest, so they are not guaranteed to be identical to the implementation written during the contest.

Many of these implementations are publicly available as contest submissions, but some are not. Even for public submissions, the library includes are left unexpanded, so you can read only the problem-specific part of the code. This may be easier than locating and reading the implementation on the contest submission page.

## Finding problems by difficulty or tags

For common beginner-level topics, there are many better curated resources available elsewhere, so I do not think this repository provides much value in that area.

On the other hand, [`index/difficulty.md`](index/difficulty.md) may be useful when looking for harder problems, while [`index/tags.md`](index/tags.md) may help when searching for rarely covered topics or typical techniques for intermediate to advanced users.

## Finding problems by library usage

[`index/includes.md`](index/includes.md) contains problem lists grouped by direct includes in `main.cpp`.

For example, you can find problems that use:

```cpp
#include "ds/segtree/segtree.hpp"
```

or:

```cpp
#include "graph/tree_dp/rerooting_dp.hpp"
```

The implementations of these libraries are available at:

https://github.com/maspypy/library

This may be useful when looking for real use cases of a specific library, or when looking for practice problems involving uncommon implementation patterns.

However, this index only considers includes written directly in `main.cpp`. It does not include indirect dependencies included from inside the library.

For frequently used libraries, `index/includes.md` may show only part of the list. The complete list is kept in the `includes` column of `index/problems.tsv`.

## Performing more advanced searches

By cloning the repository and using `grep`, or by processing `index/problems.tsv`, you can perform more advanced searches. For example, you can:

- Search for `main.cpp` files that `#include` `ds/segtree/segtree.hpp` and also contain the string `seg.max_right`
- Find problems with a specific tag within a specific difficulty range
- Find problems that `#include` a specific library within a specific difficulty range
