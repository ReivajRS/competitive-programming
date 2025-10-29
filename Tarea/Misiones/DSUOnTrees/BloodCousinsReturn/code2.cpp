#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 1;
int id[maxn], sz[maxn], depth[maxn], sz_depth_ids[maxn], in_deg[maxn], ans[maxn];
map<string, int> names;
map<int, set<int>> depth_ids[maxn];
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

void dfs(int u) {
  sz_depth_ids[u] += !depth_ids[u][depth[u]].count(id[u]);
  depth_ids[u][depth[u]].insert(id[u]);
  for (int v : g[u]) {
    dfs(v);
    if (sz_depth_ids[u] < sz_depth_ids[v]) {
      swap(sz_depth_ids[u], sz_depth_ids[v]);
      swap(depth_ids[u], depth_ids[v]);
    }
    for (auto& [d, ids] : depth_ids[v]) {
      auto& depth_d_ids = depth_ids[u][d];
      for (int x : ids) {
        sz_depth_ids[u] += !depth_d_ids.count(x);
        depth_d_ids.insert(x);
      }
      ids.clear();
    }
    depth_ids[v].clear();
  }
  for (auto [d, idx] : queries[u]) {
    ans[idx] = int(depth_ids[u][d].size());
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
      dfs(i);
    }
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}