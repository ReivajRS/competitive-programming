#include <bits/stdc++.h>
using namespace std;


void dfs(int u, vector<vector<int>>& g, vector<bool>& vis, vector<int>& order) {
  vis[u] = 1;
  for (int v : g[u]) if (!vis[v]) {
    dfs(v, g, vis, order);
  }
  order.push_back(u);
}

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = i + 1; j < n; j++) {
      if (s[j] == '1') {
        g[i].push_back(j);
      }
    }
  }
  vector<bool> vis(n);
  vector<int> order;
  for (int u = 0; u < n; u++) if (!vis[u]) {
    dfs(u, g, vis, order);
  }
  for (int i = n - 1; i >= 0; i--) {
    cout << order[i] + 1 << " \n"[i == 0];
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}