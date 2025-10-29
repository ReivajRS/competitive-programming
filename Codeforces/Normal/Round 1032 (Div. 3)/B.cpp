#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> cnt(26);
  for (auto c : s) {
    cnt[c - 'a']++;
  }
  for (int i = 1; i < SZ(s) - 1; i++) {
    if (cnt[s[i] - 'a'] > 1) {
      cout << "Yes" << '\n';
      return;
    }
  }
  cout << "No" << '\n';
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