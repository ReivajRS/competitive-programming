#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vi a(n), b(n + 1, -1), last(n + 1);
  FOR (i, 0, n) {
    cin >> a[i];
    last[i] = b[a[i]];
    b[a[i]] = i;
  }
  vi dp(n, 0);
  FOR (i, 1, n) {
    dp[i] = dp[i - 1];
    int l = last[i];
    if (l == -1)
      continue;
    if (l >= 0)
      dp[i] = max(dp[i], i - l + 1 + dp[l - 1]);
    dp[i] = max(dp[i], i - l + dp[l]);
  }
  cout << dp[n - 1] << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}