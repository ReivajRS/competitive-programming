#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> s(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  vector<int> dp(n, 1e9);
  for (int i = 0; i < n; i++) {
    dp[i] = c[i];
  }

  for (int k = 0; k < 2; k++) {
    vector<int> ndp(n, 1e9);
    for (int i = n - 1; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        if (s[j] > s[i]) {
          ndp[j] = min(ndp[j], dp[i] + c[j]);
        }
      }
    }
    dp = ndp;
  }
  
  int ans = *min_element(dp.begin(), dp.end());
  if (ans == 1e9) {
    ans = -1;
  }
  cout << ans << '\n';
  
  return 0;
}