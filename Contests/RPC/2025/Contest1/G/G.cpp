#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  string s;
  cin >> s;

  int sq = 500;
  const int mod = 1e9 + 7;

  int N = n + sq + 5;
  for (int i = 0; i < N - n; ++i) {
    s += '.';
  }

  vector<vector<int>> dp(N, vector<int>(sq + 1, 0));
  for (int i = n; i < N; ++i) {
    for (int j = 0; j <= sq; ++j) {
      dp[i][j] = 1;
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= sq; ++j) {
      if (s[i + 1] == '.') {
        dp[i][j] = dp[i + 1][j];
      }
      if (j < sq && s[i + j + 2] == '.') {
        dp[i][j] = (dp[i][j] + dp[i + j + 2][j + 1]) % mod;
      }
    }
  }
  cout << dp[0][0] << '\n';

  return 0;
}