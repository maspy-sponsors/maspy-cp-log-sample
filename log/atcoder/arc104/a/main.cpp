#include "my_template.hpp"
#include "other/io.hpp"

void solve() {
  LL(a, b);
  ll x = (a + b) / 2;
  ll y = (a - b) / 2;
  print(x, y);
}

int main() { solve(); }