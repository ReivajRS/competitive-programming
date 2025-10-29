#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int l = 0, ans = n;
  for (int r = 2; r < n; r++) {
    while (l + 1 < r && a[l] + a[l + 1] <= a[r]) {
      l++;
    }
    ans = min(ans, l - 1 + n - r);
  }
  cout << ans << '\n';
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