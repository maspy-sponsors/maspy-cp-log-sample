#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  STR(S);
  reverse(all(S));

  string T;
  for (auto& x : S) {
    T += x;
    if (x == 'A') {
      if (len(T) >= 3 && T.substr(len(T) - 3) == "CBA") {
        T.pop_back();
        T.pop_back();
        T.pop_back();
      }
      elif (len(T) >= 2 && T.substr(len(T) - 2) == "BA") {
        T.pop_back();
        T.pop_back();
      }
      else {
        T.pop_back();
      }
    }
  }
  print(len(T));
}

signed main() {
  INT(T);
  FOR(T)
  solve();
}