#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<bool> vis(n);
  auto dfs = [&](auto&& self, int u) -> int {
    vis[u] = true;
    int sz = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        sz += self(self, v);
      }
    }
    return sz;
  };
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      ans = max(ans, dfs(dfs, i));
    }
  }
  cout << ans << '\n';
  return 0;
}