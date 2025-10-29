#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<ll> a(n + 1), b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }

  vector<vector<int>> g(n + 1);
  vector<pair<int, int>> edges;
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edges.push_back({u, v});
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> dist(n + 1, -1);
  queue<int> q;
  q.push(0);
  dist[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int &v : g[u]) if (dist[v] == -1) {
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }

  vector<ll> ans(n + 1, -1e18);
  ll mx = -1e18;
  for (int i = 0; i < n; i++) {
    ans[i] = max(ans[i], mx);
    mx = max(mx, a[i] - b[i] * (dist[i] + 1));
  }
  mx = -1e18;
  for (int i = n - 1; i >= 0; i--) {
    ans[i] = max(ans[i], mx);
    mx = max(mx, a[i] - b[i] * (dist[i] + 1));
  }

  vector<vector<int>> g2(2 * n + 1);
  for (auto &[u, v] : edges) {
    if (dist[u] > dist[v]) {
      swap(u, v);
    }
    if (dist[v] == dist[u] + 1) {
      g2[u].push_back(v);
      g2[u + n].push_back(v + n);
    }
    if (dist[v] == dist[u]) {
      g2[u].push_back(v + n);
      g2[v].push_back(u + n);
    }
  }

  vector<int> order;
  vector<bool> vis(2 * n + 1);
  auto toposort = [&](auto &toposort, int u) -> void {
    vis[u] = 1;
    for (int &v : g2[u]) if (!vis[v]) {
      toposort(toposort, v);
    }
    order.push_back(u);
  };
  
  for (int i = 0; i < 2 * n; i++) {
    if (!vis[i]) {
      toposort(toposort, i);
    }
  }

  vector<ll> dp(2 * n + 1, -1e18);
  for (int &u : order) {
    for (int &v : g2[u]) {
      dp[u] = max(dp[u], dp[v]);
      if (v <= n) {
        dp[u] = max(dp[u], a[v] - b[v] * (dist[v] - 1));
      }
      else {
        dp[u] = max(dp[u], a[v - n] - b[v - n] * dist[v - n]);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (dist[i] == 1) {
      ans[i] = max(ans[i], dp[i]);
      cout << ans[i] << '\n';
    }
  }

  return 0;
}