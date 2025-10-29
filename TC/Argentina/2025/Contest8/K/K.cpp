#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy y la Alexbriza 

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, k;
  cin >> n >> m >> k;

  vector<bool> busy(n);
  while (k--) {
    int i;
    cin >> i;
    --i;
    busy[i] = true;
  }

  vector<vector<int>> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v), g[v].push_back(u);
  }
  
  int st = 0;
  while (st < n && busy[st]) {
    ++st;
  }
  
  if (st == n) {
    cout << "No\n";
    return 0;
  }

  vector<vector<int>> ans(n);
  vector<bool> vis(n);
  vector<int> order;
  auto dfs = [&](auto&& dfs, int u) -> void {
    vis[u] = true;
    if (busy[u]) {
      return;
    }
    bool added = false;
    for (int v : g[u]) {
      if (!vis[v]) {
        if (!added) {
          order.push_back(u);
          added = true;
        }
        ans[u].push_back(v);
        dfs(dfs, v);
      }
    }
  };
  dfs(dfs, st);

  if (count(vis.begin(), vis.end(), false)) {
    cout << "No\n";
    return 0;
  }
  
  cout << "Yes\n";
  cout << order.size() << '\n';
  for (int i : order) {
    cout << i + 1 << ' ' << ans[i].size() << ' ';
    for (int j : ans[i]) {
      cout << j + 1 << ' ';
    }
    cout << '\n';
  }
}