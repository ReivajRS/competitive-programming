#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

int n;
int c[11][11];
int dp[11][2049];
const int INF = 1e9;

int f(int i, int mask) {
  mask |= 1 << i;
  if (mask == (1 << (n + 1)) - 1) {
    return 0;
  }
  int &ans = dp[i][mask];
  if (ans != -1) {
    return ans;
  }
  ans = INF;
  for (int j = 1; j <= n; j++) {
    if (!(mask & (1 << j)) && i != j) {
      ans = min(ans, c[i][j] + f(j, mask));
    }
  }
  return ans;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c[i][j];
    }
  }

  memset(dp, -1, sizeof dp);

  cout << f(0, 0) << '\n';

  return 0;
}