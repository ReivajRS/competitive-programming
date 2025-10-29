#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  string s;
  cin >> s;

  for (int i = 0; i < SZ(s) - 1; i++) {
    if (s[i] == s[i + 1]) {
      cout << 1 << '\n';
      return;
    }
  }

  cout << SZ(s) << '\n';
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