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

const int MAXN = 3001, INF = 1e9;
int n;
int s[MAXN], c[MAXN];
int dp[MAXN][MAXN][4];

int solve(int i, int last, int cnt) {
  if (i == n) {
    return cnt == 3 ? 0 : INF;
  }
  int &ans = dp[i][last][cnt];
  if (ans != -1)
    return ans;
  ans = solve(i + 1, last, cnt);
  if (cnt == 0 || s[i] > s[last])
    ans = min(ans, solve(i + 1, i, cnt + 1) + c[i]);
  return ans;
}

signed main() { __
  cin >> n;

  FOR (i, 0, n) {
    cin >> s[i];
  }
  FOR (i, 0, n) {
    cin >> c[i];
  }

  // Recursive DP
  memset(dp, -1, sizeof dp);

  int ans = solve(0, 0, 0);

  if (ans >= INF)
    ans = -1;
  
  cout << ans << ENDL;

  // Iterative DP

  // int dp[MAXN][4];

  // FOR (i, 0, MAXN) {
  //   FOR (j, 0, 4) {
  //     dp[i][j] = INF;
  //   }
  // }

  // dp[0][0] = 0;

  // FOR (i, 1, n + 1) {
  //   FOR (j, 0, 3) {
  //     dp[i][j] = min(dp[i][j], dp[i - 1][j]);
  //     FOR (k, 0, i) {
  //       if (s[i] > s[k])
  //         dp[i][j + 1] = min(dp[i][j + 1], dp[k][j] + c[i]);
  //     }
  //   }
  // }

  // cout << (dp[n - 1][3] >= INF ? -1 : dp[n - 1][3]) << ENDL;

  return 0;
}