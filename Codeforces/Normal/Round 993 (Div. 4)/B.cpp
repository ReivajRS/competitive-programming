#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (char &c : s) {
    if (c == 'p') {
      c = 'q';
      continue;
    }
    if (c == 'q') {
      c = 'p';
      continue;
    }
  }
  cout << s << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}