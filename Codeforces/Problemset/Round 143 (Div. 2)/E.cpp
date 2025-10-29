#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

struct LCA {
  int LOG;
  vector<vector<int>> up;
  vector<int> depth;

  void dfs(int u, int p, vector<vector<int>>& g) {
    for (auto v : g[u]) {
      if (v == p) {
        continue;
      }
      depth[v] = depth[u] + 1;
      up[v][0] = u;
      for (int i = 1; i < LOG; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
      }
      dfs(v, u, g);
    }
  }

  LCA(vector<vector<int>>& g, int root) {
    int n = SZ(g);
    LOG = ceil(log2(n)) + 1;
    depth.resize(n);
    up.assign(n, vector<int>(LOG));
    depth[root] = 0;
    dfs(root, -1, g);
  }

  int get(int u, int v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = LOG - 1; i >= 0; i--) {
      if (diff & (1 << i)) {
        u = up[u][i];
      }
    }
    if (u == v) {
      return u;
    }
    for (int i = LOG - 1; i >= 0; i--) {
      if (up[u][i] != up[v][i]) {
        u = up[u][i];
        v = up[v][i];
      }
    }
    return up[u][0];
  }
};

void get_back_edges(int u, int p, int& t, vector<vector<int>>& g, vector<int>& t_in, map<pair<int, int>, int>& back_edges, vector<bool>& has_back_edge_down) {
  t_in[u] = t++;
  for (auto v : g[u]) {
    if (v == p) {
      continue;
    }
    if (t_in[v] != -1) {
      if (t_in[v] < t_in[u]) {
        back_edges[{min(u, v), max(u, v)}] = SZ(back_edges);
        has_back_edge_down[v] = true;
      }
    }
    else {
      get_back_edges(v, u, t, g, t_in, back_edges, has_back_edge_down);
    }
  }
}

void get_cycles(int u, int p, vector<vector<int>>& g, vector<bool>& vis, vector<int>& cycle, map<pair<int, int>, int>& back_edges, vector<bool>& has_back_edge_down) {
  vis[u] = true;
  pair<int, int> back_edge = {-1, -1};
  int back_idx = -1;
  for (auto v : g[u]) {
    pair<int, int> edge = {min(u, v), max(u, v)};
    if (v != p) {
      if (!vis[v]) {
        get_cycles(v, u, g, vis, cycle, back_edges, has_back_edge_down);
      }
      if (back_edges.count(edge)) {
        back_edge = edge;
        back_idx = back_edges[back_edge];
      }
    }
  }
  if (back_idx != -1) {
    cycle[u] = back_idx;
  }
  else {
    cycle[u] = u;
    for (auto v : g[u]) {
      if (v != p && cycle[v] != v && !has_back_edge_down[v]) {
        cycle[u] = cycle[v];
      }
    }
  }
}

void get_cycles_from_root(int u, int p, vector<vector<int>>& g, vector<int>& cycles_from_root, int& n) {
  cycles_from_root[u] += u >= n;
  for (auto v : g[u]) {
    if (v == p) {
      continue;
    }
    cycles_from_root[v] = cycles_from_root[u];
    get_cycles_from_root(v, u, g, cycles_from_root, n);
  }
}

int binpow(int a, int b, int mod = (int)1e9 + 7) {
  int res = 1;
  a %= mod;
  while (b) {
    if (b & 1) {
      res = 1ll * res * a % mod;
    }
    a = 1ll * a * a % mod;
    b >>= 1;
  }
  return res;
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

  int t = 0;
  vector<int> t_in(n, -1);
  vector<bool> has_back_edge_down(n);
  map<pair<int, int>, int> back_edges;
  get_back_edges(0, -1, t, g, t_in, back_edges, has_back_edge_down);

  for (auto &[x, y] : back_edges) {
    y += n;
  }

  vector<bool> vis(n);
  vector<int> cycle(n, -1);
  get_cycles(0, -1, g, vis, cycle, back_edges, has_back_edge_down);
  
  int mx_id = *max_element(cycle.begin(), cycle.end());

  vector<vector<int>> g2(mx_id + 1);

  for (int i = 0; i < n; i++) {
    int c = cycle[i];
    for (auto v : g[i]) {
      if (cycle[v] != c) {
        g2[c].push_back(cycle[v]);
      }
    }
  }

  LCA lca(g2, cycle[0]);

  vector<int> cycles_from_root(SZ(g2));
  get_cycles_from_root(cycle[0], -1, g2, cycles_from_root, n);

  int q;
  cin >> q;

  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    int cu = cycle[u], cv = cycle[v];
    int ancestor = lca.get(cu, cv);
    int cycles_in_path = cycles_from_root[cu] + cycles_from_root[cv];
    cycles_in_path -= cycles_from_root[ancestor] * 2;
    cycles_in_path += ancestor >= n;
    cout << binpow(2, cycles_in_path) << '\n';
  }

  return 0;
}