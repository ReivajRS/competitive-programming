#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)b - 1; i >= (int)a; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;
  int x[n * n], y[n * n];
  FOR (i, 0, n) {
    FOR (j, 0, n) {
      int k;
      cin >> k;
      k--;
      x[k] = i, y[k] = j;
    }
  }

  int dp[n][2];
  memset(dp, 0, sizeof dp);
  for (int k = n * n - 1; k >= 0; k--) {
    int dy = dp[y[k]][1];
    dp[y[k]][1] = max(dp[y[k]][1], dp[x[k]][0] + 1);
    dp[x[k]][0] = max(dp[x[k]][0], dy + 1);
  }

  int ans = 0;
  FOR (i, 0, n) {
    ans = max({ans, dp[i][0], dp[i][1]});
  }
  cout << ans << ENDL;

  return 0;
}