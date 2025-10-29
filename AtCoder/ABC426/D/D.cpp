#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int c0 = int(count(s.begin(), s.end(), '0'));
  int c1 = int(count(s.begin(), s.end(), '1'));
  
  if (c0 == 0 || c1 == 0) {
    cout << 0 << '\n';
    return;
  }
  
  auto f = [&](char c) -> int {
    int mx = 0;
    int l = 0, r = 0;
    while (l < n) {
      if (s[l] != c) {
        l++;
        continue;
      }
      r = l;
      while (r < n && s[r] == s[l]) {
        r++;
      }
      int len = r - l;
      mx = max(mx, len);
      l = r;
    }
    int cost = c0 * (c == '0' ? 2 : 1) + c1 * (c == '1' ? 2 : 1) - mx * 2;
    return cost;
  };

  cout << min(f('0'), f('1')) << '\n';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}