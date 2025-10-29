#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    a[i] = (int)s.size();
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    if (sum > m) {
      cout << i << '\n';
      return;
    }
  }
  cout << n << '\n';
}

signed main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}