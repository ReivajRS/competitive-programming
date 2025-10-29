#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5 + 1, LOG = 18;
int sz[maxn], depth[maxn], in_deg[maxn], cnt_depth[maxn], ans[maxn];
vector<int> g[maxn], children[maxn];
int up[maxn][LOG];
vector<pair<int, int>> queries[maxn];

void init_dfs(int u, int d) {
  sz[u] = 1;
  depth[u] = d;
  for (int v : g[u]) {
    init_dfs(v, d + 1);
    sz[u] += sz[v];
  }
}

int get_kth_ancestor(int u, int k) {
  for (int i = LOG - 1; i >= 0; i--) {
    if (k >> i & 1) {
      u = up[u][i];
    }
  }
  return u;
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
  cnt_depth[depth[u]]++;
  for (int v : g[u]) {
    if (v != heavy_child) {
      for (int x : children[v]) {
        cnt_depth[depth[x]]++;
        children[u].push_back(x);
      }
    }
  }
  for (auto [d, idx] : queries[u]) {
    ans[idx] = cnt_depth[d] - 1;
  }
  if (!is_heavy) {
    for (int v : children[u]) {
      cnt_depth[depth[v]]--;
    }
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
    up[i][0] = p;
    if (p != 0) {
      in_deg[i]++;
    }
  }

  for (int i = 1; i < LOG; i++) {
    for (int u = 1; u <= n; u++) {
      up[u][i] = up[up[u][i - 1]][i - 1];
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
    int v, p;
    cin >> v >> p;
    int ancestor = get_kth_ancestor(v, p);
    if (ancestor == 0) {
      ans[i] = 0;
      continue;
    }
    queries[ancestor].push_back({depth[ancestor] + p, i});
  }

  for (int i = 1; i <= n; i++) {
    if (!in_deg[i]) {
      dfs(i, 0);
    }
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}