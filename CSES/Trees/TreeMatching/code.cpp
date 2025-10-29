#include <bits/stdc++.h>
using namespace std;

void dfs(int u, int p, vector<vector<int>>& g, vector<vector<int>>& dp) {
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    dfs(v, u, g, dp);
    dp[u][0] += dp[v][1];
  }
  for (int v : g[u]) {
    if (v == p) {
      continue;
    }
    dp[u][1] = max(dp[u][1], dp[u][0] - dp[v][1] + dp[v][0] + 1);
  }
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

  vector<vector<int>> dp(n, vector<int>(2));

  dfs(0, -1, g, dp);
  
  cout << max(dp[0][0], dp[0][1]) << '\n';
  
  return 0;
}