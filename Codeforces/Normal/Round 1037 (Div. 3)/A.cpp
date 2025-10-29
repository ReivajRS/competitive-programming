#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  string s;
  cin >> s;
  for (char d = '0'; d <= '9'; d++) {
    for (char c : s) {
      if (d == c) {
        cout << d << '\n';
        return;
      }
    }
  }
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