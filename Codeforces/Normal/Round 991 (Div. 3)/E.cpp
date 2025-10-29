#include <bits/stdc++.h>
using namespace std;

void solve() {
  string a, b, c;
  cin >> a >> b >> c;
  int n = (int)a.size();
  int m = (int)b.size();

  const int INF = (int)1e8;
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));

  auto f = [&](auto &f, int i, int j) -> int {
    if (i == n && j == m) return 0;
    int &ans = dp[i][j];
    if (ans != INF) return ans;
    int k = i + j;
    if (i < n) {
      if (c[k] == a[i]) ans = min(ans, f(f, i + 1, j));
      ans = min(ans, f(f, i + 1, j) + 1);
    }
    if (j < m) {
      if (c[k] == b[j]) ans = min(ans, f(f, i, j + 1));
      ans = min(ans, f(f, i, j + 1) + 1);
    }
    return ans;
  };

  cout << f(f, 0, 0) << '\n';
}

signed main() {
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}