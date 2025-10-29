#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;

  int ans = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < k; j++) {
      if (s[j % i] != s[j % ans]) {
        if (s[j % i] < s[j % ans]) {
          ans = i;
        }
        break;
      }
    }
  }

  for (int i = 0; i < k; i++) {
    cout << s[i % ans];
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  // cin >> tc;
  tc = 1;

  while (tc--) {
    solve();
  }
  
  return 0;
}