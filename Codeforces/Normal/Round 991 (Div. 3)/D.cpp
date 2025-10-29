#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int i = 0; i < n; i++) {
    int mx = s[i];
    for (int j = i + 1; j < i + 10; j++) {
      if (j >= n) break;
      int dif = j - i;
      if (s[j] - dif > mx) {
        for (int l = j; l >= i + 1; l--) {
          swap(s[l - 1], s[l]);
        }
        s[i] -= dif;
        mx = s[i];
      }
    }
  }
  cout << s << '\n';
}

signed main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}