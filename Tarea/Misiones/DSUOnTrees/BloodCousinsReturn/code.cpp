#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 1;
int id[maxn], sz[maxn], depth[maxn], in_deg[maxn], ans[maxn];
map<string, int> names;
map<int, int> depth_ids[maxn];
vector<int> g[maxn], children[maxn];
vector<pair<int, int>> queries[maxn];

void init_dfs(int u, int d) {
  sz[u] = 1;
  depth[u] = d;
  for (int v : g[u]) {
    init_dfs(v, d + 1);
    sz[u] += sz[v];
  }
}

void dfs(int u, bool is_heavy) {
  int mx_sz = -1, heavy_child = -1;
  for (int v : g[u]) {
    if (sz[v] > mx_sz) {
      mx_sz = sz[v];
      heavy_child = v;
    }
  }
  for (int v : g[u]) {
    if (v != heavy_child) {
      dfs(v, 0);
    }
  }
  if (heavy_child != -1) {
    dfs(heavy_child, 1);
    swap(children[u], children[heavy_child]);
  }
  children[u].push_back(u);
  depth_ids[depth[u]][id[u]]++;
  for (int v : g[u]) {
    if (v != heavy_child) {
      for (int x : children[v]) {
        depth_ids[depth[x]][id[x]]++;
        children[u].push_back(x);
      }
    }
  }
  for (auto [d, idx] : queries[u]) {
    ans[idx] = int(depth_ids[d].size());
  }
  if (!is_heavy) {
    for (int v : children[u]) {
      auto& depth_v_ids = depth_ids[depth[v]];
      depth_v_ids[id[v]]--;
      if (depth_v_ids[id[v]] == 0) {
        depth_v_ids.erase(id[v]);
      }
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    string s;
    int p;
    cin >> s >> p;
    if (!names.count(s)) {
      names[s] = int(names.size());
    }
    id[i] = names[s];
    g[p].push_back(i);
    if (p != 0) {
      in_deg[i]++;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!in_deg[i]) {
      init_dfs(i, 0);
    }
  }

  int m;
  cin >> m;
  
  for (int i = 0; i < m; i++) {
    int v, k;
    cin >> v >> k;
    if (depth[v] + k >= maxn) {
      ans[i] = 0;
      continue;
    }
    queries[v].push_back({depth[v] + k, i});
  }

  for (int i = 1; i <= n; i++) {
    if (!in_deg[i]) {
      dfs(i, 0);
    }
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}