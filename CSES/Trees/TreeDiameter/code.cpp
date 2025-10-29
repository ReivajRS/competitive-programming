#include <bits/stdc++.h>
using namespace std;

int dfs(int u, int p, int d, vector<vector<int>>& g, vector<int>& dp) {
  if (int(g[u].size()) == 1 && g[u][0] == p) {
    return d;
  }
  int mx1 = -1, mx2 = -1;
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    int dv = dfs(v, u, d + 1, g, dp);
    if (dv > mx1) {
      mx2 = mx1;
      mx1 = dv;
    }
    else if (dv > mx2) {
      mx2 = dv;
    }
  }
  if (mx1 != 0 && mx2 != 0) {
    dp[u] = mx1 + mx2 - 2 * d;
  }
  dp[u] = max(dp[u], mx1);
  return mx1;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dp(n);

  dfs(0, -1, 0, g, dp);

  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << '\n';
  
  return 0;
}