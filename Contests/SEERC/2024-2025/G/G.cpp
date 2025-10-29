#include <bits/stdc++.h>
using namespace std;

using ll =  long long;
using vi = vector<int>;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  map<int, int> mx, occ;
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    int k = occ[a[i]]++;
    dp[i] = dp[i - 1];
    if (k) {
      dp[i] = max(dp[i], 1 + k + mx[a[i]]);
    }
    mx[a[i]] = max(mx[a[i]], dp[i - 1] - k);
  }
  cout << dp[n] << '\n';

  return 0;
}