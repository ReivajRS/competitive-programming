#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  int days = 0;
  for (int i = 0; i < n; i++) {
    if (!a[i]) {
      days++;
    }
    else {
      days = 0;
    }
    if (days == k) {
      cnt++;
      days = 0;
      i++;
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