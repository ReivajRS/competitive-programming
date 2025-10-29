#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  string line;
  getline(cin, line);

  string s = "";
  for (char c : line) {
    if (c == '<' || c == '>' || c == '+' || c == '-' || c == '.' || c == ',' || c == '[' || c == ']') {
      s += c;
    }
  }

  cout << s << '\n';

  return 0;
}