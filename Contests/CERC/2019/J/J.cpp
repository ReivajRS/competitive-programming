#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

void dfs(int u, vector<vector<int>>& g, vector<bool>& vis) {
  vis[u] = true;
  for (int v : g[u]) {
    if (!vis[v]) {
      dfs(v, g, vis);
    }
  }
}

int solve(vector<vector<int>>& g, vector<bool>& vis) {
  int ret = 0;
  for (int u = 0; u < (int)g.size(); ++u) {
    if (!vis[u]) {
      dfs(u, g, vis);
      ++ret;
    }
  }
  return ret;
} 

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, e, p;
  cin >> n >> e >> p;

  vector<vector<int>> g(n);
  set<pair<int, int>> st;
  for (int i = 0; i < e; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    g[u].push_back(v);
    g[v].push_back(u);
    st.emplace(min(u, v), max(u, v));
  }

  const int B = 320;
  while (p--) {
    int m;
    cin >> m;
    
    vector<int> nodes(m);
    for (int& u : nodes) {
      cin >> u;
      --u;
    }

    if (m > B) {
      vector<bool> vis(n, true);
      for (int u : nodes) {
        vis[u] = false;
      }
      cout << solve(g, vis) << '\n';
      continue;
    }
    vector<vector<int>> g2(m);
    for (int i = 0; i < m; ++i) {
      int u = nodes[i];
      for (int j = i + 1; j < m; ++j) {
        int v = nodes[j];
        if (st.count(make_pair(min(u, v), max(u, v)))) {
          g2[i].push_back(j);
          g2[j].push_back(i);
        }
      }
    }
    vector<bool> vis(m);
    cout << solve(g2, vis) << '\n';
  }

  return 0;
}