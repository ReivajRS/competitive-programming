#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie()->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, ll>>> g(n + 1);

  for (int i = 0; i < m; i++) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, -w});
  }

  vector<bool> vis(n + 1);
  vector<ll> val(n + 1);

  auto dfs = [&](auto &dfs, int u) -> void {
    vis[u] = 1;
    for (auto [v, w] : g[u]) if (!vis[v]) {
      val[v] = val[u] + w;
      dfs(dfs, v);
    }
  };

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      val[i] = 0;
      dfs(dfs, i);
    }
  }

  for (int i = 0; i < n; i++) {
    cout << val[i] << " \n"[i == n - 1];
  }

  return 0;
}