#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  ll n, m, k;
  cin >> n >> m >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  vector<vector<ll>> dp(n + 1, vector<ll>(m, -k));

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      dp[i][j] = dp[i - 1][(j - 1 + m) % m] + a[i - 1] - k * (j == 0);
      dp[i][j] = max(dp[i][j], a[i - 1] - k);
      ans = max(ans, dp[i][j]);
    }
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  tc = 1;

  while (tc--) {
    solve();
  }

  return 0;
}