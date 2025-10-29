#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  for (auto &x : a) {
    cin >> x;
    mp[x]++;
  }
  int c = -1;
  for (auto &[x, y] : mp) {
    if (y >= 2) {
      c = x;
    }
  }
  if (c == -1) {
    cout << -1 << '\n';
    return;
  }
  mp[c] -= 2;
  vector<int> b;
  for (auto &[x, y] : mp) {
    for (int i = 0; i < y; i++) {
      b.push_back(x);
    }
  }
  for (int i = 0; i < (int)b.size(); i++) {
    if (abs(b[i] - b[i + 1]) < 2 * c) {
      cout << b[i] << ' ' << b[i + 1] << ' ' << c << ' ' << c << '\n';
      return;
    }
  }
  cout << -1 << '\n';
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