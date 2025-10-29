#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void init_dfs(int u, int d, vector<vector<int>>& g, vector<int>& sz, vector<int>& depth) {
  sz[u] = 1;
  depth[u] = d;
  for (int v : g[u]) {
    init_dfs(v, d + 1, g, sz, depth);
    sz[u] += sz[v];
  }
}

void dfs(int u, bool is_heavy, vector<vector<int>>& g, vector<int>& sz, vector<int>& depth, vector<vector<int>>& children, string& s, vector<int>& cnt, vector<vector<pair<int, int>>>& queries, vector<bool>& ans) {
  int mx_sz = -1, heavy_child = -1;
  for (int v : g[u]) {
    if (sz[v] > mx_sz) {
      mx_sz = sz[v];
      heavy_child = v;
    }
  }
  for (int v : g[u]) {
    if (v != heavy_child) {
      dfs(v, 0, g, sz, depth, children, s, cnt, queries, ans);
    }
  }
  if (heavy_child != -1) {
    dfs(heavy_child, 1, g, sz, depth, children, s, cnt, queries, ans);
    swap(children[u], children[heavy_child]);
  }
  children[u].push_back(u);
  cnt[depth[u]] ^= 1 << (s[u] - 'a');
  for (int v : g[u]) {
    if (v != heavy_child) {
      for (int x : children[v]) {
        cnt[depth[x]] ^= 1 << (s[x] - 'a');
        children[u].push_back(x);
      }
    }
  }
  for (auto [h, idx] : queries[u]) {
    ans[idx] = __builtin_popcount(cnt[h]) <= 1;
  }
  if (!is_heavy) {
    for (int v : children[u]) {
      cnt[depth[v]] ^= 1 << (s[v] - 'a');
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  
  string s;
  cin >> s;

  vector<vector<pair<int, int>>> queries(n);

  for (int i = 0; i < m; i++) {
    int v, h;
    cin >> v >> h;
    queries[v - 1].push_back({h - 1, i});
  }

  vector<int> sz(n), depth(n);
  init_dfs(0, 0, g, sz, depth);
  vector<vector<int>> children(n);
  vector<int> cnt(n);
  vector<bool> ans(m);

  dfs(0, 0, g, sz, depth, children, s, cnt, queries, ans);

  for (int i = 0; i < m; i++) {
    cout << (ans[i] ? "Yes" : "No") << '\n';
  }
  
  return 0;
}