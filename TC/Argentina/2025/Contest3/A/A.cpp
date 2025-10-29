#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end());

  vector<int> dp(n + 1);
  for (int i = 0; i < n; i++) {
    int l = a[i].first - a[i].second;
    int j = int(lower_bound(a.begin(), a.end(), make_pair(l, 0)) - a.begin());
    if (j > 0) {
      dp[i] = dp[j - 1];
    }
    dp[i] += i - j;
  }

  int ans = n;
  for (int i = 0; i < n; i++) {
    ans = min(ans, dp[i] + n - i - 1);
  }

  cout << ans << '\n';

  return 0;
}