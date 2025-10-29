#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define ROF(i, a, b) for(int i = (int)a - 1; i >= b; i--)
#define ENDL '\n'

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &ai : a) {
    cin >> ai;
  }
  vi dp(n + 1, 0);
  ROF (i, n, 0) {
    dp[i] = 1 + dp[i + 1];
    if (i + a[i] + 1 <= n) {
      dp[i] = min(dp[i], dp[i + a[i] + 1]);
    }
  }
  cout << dp[0] << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int t;
  cin >> t;
  while (t--) solve();

  return 0;
}