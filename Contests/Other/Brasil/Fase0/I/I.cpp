#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, T;
  cin >> n >> T;

  vector<vector<int>> c(n, vector<int>(T));
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < T; t++) {
      cin >> c[i][t];
    }
  }

  int L, U;
  cin >> L >> U;

  vector<vector<ll>> pref(n, vector<ll>(T + 1));
  for (int i = 0; i < n; i++) {
    for (int t = 0; t < T; t++) {
      pref[i][t + 1] = pref[i][t] + c[i][t];
    }
  }

  vector<ll> dp(T + 1, -1);
  dp[0] = 0;

  for (int t = 1; t <= T; t++) {
    for (int len = L; len <= U; len++) {
      int start = t - len;
      if (start < 0) {
        continue;
      }
      for (int i = 0; i < n; i++) {
        ll sum = pref[i][t] - pref[i][start];
        if (dp[start] != -1) {
          dp[t] = max(dp[t], dp[start] + sum);
        }
      }
    }
  }

  cout << dp[T] << '\n';

  return 0;
}