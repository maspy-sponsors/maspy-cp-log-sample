#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  STR(S);
  vc<string> A;
  S += ',';
  string now;
  for (char c : S) {
    if (c == ';' || c == ',') {
      A.eb(now);
      now = "";
    } else {
      now += c;
    }
  }
  vc<string> NUM;
  vc<string> OTHER;
  auto isnum = [&](string x) -> bool {
    if (x == "0") return true;
    if (x.size() == 0 || x[0] == '0') return false;
    for (char c : x) {
      if (c - '0' < 0 || '9' - '0' < c - '0') return false;
    }
    return true;
  };
  for (string x : A) {
    if (isnum(x))
      NUM.eb(x);
    else
      OTHER.eb(x);
  }

  auto to_str = [&](vc<string> A) -> string {
    string ANS;
    ANS += '"';
    for (string x : A) {
      ANS += x;
      ANS += ',';
    }
    ANS.pop_back();
    ANS += '"';
    if (ANS.size() == 1) ANS = "-";
    return ANS;
  };
  print(to_str(NUM));
  print(to_str(OTHER));
}

signed main() {
  solve();

  return 0;
}