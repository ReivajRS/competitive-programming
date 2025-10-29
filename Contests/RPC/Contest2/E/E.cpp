#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; i--)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

signed main() { __
  int n;
  cin >> n;
  vi s(n + 1, 0), p(n + 1, 0), e(n + 1, 0), a(n + 1, 0);
  FOR (i, 1, n + 1) {
    cin >> s[i] >> p[i] >> e[i] >> a[i];
  }

  vector<vi> dp(n + 1, vi(n + 1, -1e9));
  dp[0][0] = s[1];
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j != i) dp[i][j] = dp[i - 1][j] + (i != n ? s[i + 1] - e[i] : 0);
      if (j && dp[i - 1][j - 1] >= a[i]) {
        dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - a[i] + (i != n ? s[i + 1] - p[i] : 0));
      }
    }
  }

  int ans = 0;
  FOR (i, 1, n + 1) {
    if (dp[n][i] >= 0) ans = i;
  }
  cout << ans << ENDL;

  return 0;
}