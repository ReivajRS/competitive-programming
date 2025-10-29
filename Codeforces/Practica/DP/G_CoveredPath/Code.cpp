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

const int INF = 1e7, MAXN = 101, MAXV = 1101;
int v1, v2, t, d;
int dp[MAXN][MAXV];

int solve(int i, int v) {
  if (i == t) {
    return v == v2 ? 0 : -INF;
  }
  int &ans = dp[i][v];
  if (ans != -1)
    return ans;
  ans = max(-INF, solve(i + 1, v) + v);
  FOR (delta, 1, d + 1) {
    ans = max(ans, solve(i + 1, v + delta) + v + delta);
    ans = max(ans, solve(i + 1, v - delta) + v - delta);
  }
  return ans;
}

signed main() { __
  cin >> v1 >> v2 >> t >> d;

  // memset(dp, -1, sizeof dp);

  // cout << solve(1, v1) + v1 << ENDL;

  FOR (i, 0, MAXN) {
    FOR (j, 0, MAXV) {
      dp[i][j] = -INF;
    }
  }

  dp[0][v1] = 0;

  FOR (i, 0, MAXN - 1) {
    FOR (j, 0, MAXV - 1) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + j);
      FOR (delta, 1, d + 1) {
        if (j + delta < MAXV)
          dp[i + 1][j + delta] = max(dp[i + 1][j + delta], dp[i][j] + j);
        if (j - delta >= 0)
          dp[i + 1][j - delta] = max(dp[i + 1][j - delta], dp[i][j] + j);
      }
    }
  }

  cout << dp[t - 1][v2] + v2 << ENDL;
  
  return 0;
}