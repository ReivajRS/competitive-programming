#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  string s;
  cin >> s;
  int n = SZ(s);
  int idx = -1;
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != '0') {
      idx = i;
      break;
    }
    else {
      cnt++;
    }
  }
  for (int i = 0; i < idx; i++) {
    if (s[i] != '0') {
      cnt++;
    }
  }

  cout << cnt << '\n';
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