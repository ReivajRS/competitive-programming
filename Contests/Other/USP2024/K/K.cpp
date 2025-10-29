#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, w;
  cin >> n >> m >> w;

  vector<int> a(n);
  for (int& x : a) {
    cin >> x;
  }
  a.push_back(0);

  vector<vector<int>> dp(n + 1, vector<int>(m + 1));
  for (int i = n - w; i >= 0; --i) {
    for (int r = i, s = 0; r < n; ++r) {
      s += a[r];
      int x = (r - i + w) / w;
      if (x <= m) {
        dp[i][x] = max(dp[i][x], s + dp[r + 1][ ]);
      }
    }
  }
  cout << dp[0][m] << '\n';

  return 0;
}