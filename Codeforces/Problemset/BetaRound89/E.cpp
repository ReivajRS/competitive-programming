#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int p, int& t, vector<vector<int>>& g, vector<int>& t_in, vector<int>& low, vector<pair<int, int>>& edges) {
  t_in[u] = low[u] = t++;
  for (auto v : g[u]) {
    if (v == p) {
      continue;
    }
    if (t_in[v] != -1) {
      low[u] = min(low[u], t_in[v]);
      if (t_in[v] < t_in[u]) {
        edges.push_back({u, v});
      }
    }
    else {
      edges.push_back({u, v});
      if (!dfs(v, u, t, g, t_in, low, edges)) {
        return false;
      }
      low[u] = min(low[u], low[v]);
      if (low[v] > t_in[u]) {
        return false;
      }
    }
  }
  return true;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  vector<int> t_in(n, -1), low(n, -1);
  vector<pair<int, int>> edges;
  int t = 0;

  if (!dfs(0, -1, t, g, t_in, low, edges)) {
    cout << 0 << '\n';
    return 0;
  }

  for (auto [x, y] : edges) {
    cout << x + 1 << ' ' << y + 1 << '\n';
  }

  return 0;
}