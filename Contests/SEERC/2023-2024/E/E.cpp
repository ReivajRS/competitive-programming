#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

void dfs(int u, int p, vector<vector<int>>& g, vector<vector<int>>& dp) {
  int s = 0;
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, g, dp);
      s += dp[0][v];
    }
  }
  dp[0][u] = min(dp[0][u], s + 2);
  dp[1][u] = s;
  for (int v : g[u]) {
    if (v != p) {
      dp[0][u] = min(dp[0][u], s - dp[0][v] + dp[1][v] + 1);
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<vector<int>> dp(2, vector<int>(n, 1e9));
  dfs(0, -1, g, dp);
  cout << dp[0][0] << '\n';

  return 0;
}