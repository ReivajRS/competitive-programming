#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<bool> connected(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    if (v == 0) connected[u] = 1;
  }

  queue<int> q;
  vector<int> dist(n, 1e9);
  dist[0] = 0;
  q.push(0);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : g[u]) if (dist[v] == 1e9) {
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }

  int ans = 1e9;
  for (int i = 1; i < n; i++) if (connected[i]) {
    ans = min(ans, dist[i] + 1);
  }

  if (ans == 1e9) ans = -1;
  cout << ans << '\n';

  return 0;
}