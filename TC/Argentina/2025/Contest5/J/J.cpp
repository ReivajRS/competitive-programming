#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, mod;
  cin >> n >> m >> mod;

  vector<int> cnt(n, 2);
  for (int i = 0; i < m; ++i) {
    string s;
    cin >> s;
    int ones = 0;
    for (int j = 0; j < n; ++j) {
      if (s[j] == '1') {
        --cnt[j];
        ++ones;
      }
    }
  }

  vector<int> dp(n + 1);
  dp[0] = 1;
  for (int row = n - 1; row > m - 1; --row) {
    vector<int> newDp(n + 1);
    for (int i = 0; i <= n; ++i) {
      // 1-1 1-2 2-2
      int j = 2 * (n - row) - i;
      if (j < 0 || j % 2 == 1) {
        continue;
      }
      j /= 2;
      
      if (i >= 2) {
        int x = i * (i - 1) / 2 % mod;
        (newDp[i] += ll(x) * dp[i - 2] % mod) % mod;
      }
      if (i && j) {
        int x = i * j % mod;
        (newDp[i] += ll(x) * dp[i] % mod) %= mod;
      }
      if (j >= 2 && i <= n - 2) {
        int x = j * (j - 1) / 2 % mod;
        (newDp[i] += ll(x) * dp[i + 2] % mod) %= mod;
      }
    }
    dp.swap(newDp);
  }
  int ones = int(count(cnt.begin(), cnt.end(), 1));
  cout << dp[ones] << '\n';

  return 0;
}