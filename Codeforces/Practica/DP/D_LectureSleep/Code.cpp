#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() { __
  int n, k;
  cin >> n >> k;
  
  int a[n], ps[n + 1];
  ps[0] = 0;
  
  FOR (i, 0, n) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  
  bool t[n];
  
  FOR (i, 0, n) {
    cin >> t[i];
  }
  
  int dp[100001][2] = {0};
  dp[0][0] = dp[0][1] = 0;

  FOR (i, 0, n) {
    dp[i + 1][0] = max(dp[i + 1][0], dp[i][0] + a[i] * t[i]);
    dp[i + 1][1] = max(dp[i + 1][1], dp[i][1] + a[i] * t[i]);
    dp[i + k][1] = max(dp[i + k][1], dp[i][0] + (ps[i + k] - ps[i]));
  }

  cout << dp[n][1] << ENDL;

  return 0;
}