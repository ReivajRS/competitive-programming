#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

int n, m;
constexpr int MOD = 1e9 + 7;
int dp[12][1002][1 << 12];

int solve(int i, int j, int mask) {
  if (i == 0 && j == m)
    return 1;
  int &ans = dp[i][j][mask];
  if (ans != -1)
    return ans;
  ans = 0;
  if (!(mask & (1 << i))) {
    if (j + 1 < m) {
      if (i + 1 < n)
        ans += solve(i + 1, j, mask | (1 << i));
      if (i == n - 1)
        ans += solve(0, j + 1, mask | (1 << i));
    }
    if (i + 1 < n) {
      if (!(mask & (1 << (i + 1))))
        ans += solve(i + 1, j, mask | (1 << (i + 1)));
    }
  }
  else {
    if (i + 1 < n)
      ans += solve(i + 1, j, mask & ~(1 << i));
    if (i == n - 1)
      ans += solve(0, j + 1, mask & ~(1 << i));
  }
  return ans % MOD;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n >> m;

  memset(dp, -1, sizeof dp);

  cout << solve(0, 0, 0) << ENDL;

  return 0;
}