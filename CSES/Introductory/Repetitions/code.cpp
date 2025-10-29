#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  string s;
  cin >> s;

  int n = int(s.size());

  int mx = 1;
  int now = 1;
  for (int i = 1; i < n; i++) {
    if (s[i - 1] == s[i]) {
      now++;
      mx = max(mx, now);
    }
    else {
      now = 1;
    }
  }

  cout << mx << '\n';
  
  return 0;
}