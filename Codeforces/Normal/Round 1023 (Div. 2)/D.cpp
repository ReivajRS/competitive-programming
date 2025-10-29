#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void dfs(int u, int p, int dist, vector<vector<int>>& g, vector<bool>& active_nodes, vector<int>& nodes, int& mx_dist, int& node) {
  nodes.push_back(u);
  if (dist > mx_dist) {
    mx_dist = dist;
    node = u;
  }
  else if (dist == mx_dist) {
    node = max(node, u);
  }
  for (auto &v : g[u]) {
    if (v != p && active_nodes[v]) {
      dfs(v, u, dist + 1, g, active_nodes, nodes, mx_dist, node);
    }
  }
}

bool dfs_path(int u, int p, int target, vector<vector<int>>& g, vector<bool>& active_nodes, vector<int>& path) {
  if (u == target) {
    path.push_back(u);
    return true;
  }
  for (auto &v : g[u]) {
    if (v != p && active_nodes[v] && dfs_path(v, u, target, g, active_nodes, path)) {
      path.push_back(u);
      return true;
    }
  }
  return false;
}

void remove_nodes(vector<vector<int>>& g, vector<bool>& active_nodes, vector<int>& path) {
  for (auto &u : path) {
    active_nodes[u] = 0;
  }
}

pair<tuple<int, int, int>, vector<int>>
get_diameter(int u, vector<vector<int>>& g, vector<bool>& active_nodes) {
  int mx_dist = 0, node = -1;
  vector<int> nodes;
  dfs(u, -1, 1, g, active_nodes, nodes, mx_dist, node);
  mx_dist = 0;
  int node2 = -1;
  nodes.clear();
  dfs(node, -1, 1, g, active_nodes, nodes, mx_dist, node2);
  if (node < node2) {
    swap(node, node2);
  }
  vector<int> path;
  dfs_path(node, -1, node2, g, active_nodes, path);
  remove_nodes(g, active_nodes, path);
  return {{mx_dist, node, node2}, nodes};
}

void solve() {
  int n;
  cin >> n;

  vector<vector<int>> g(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  vector<bool> active_nodes(n, 1);
  vector<tuple<int, int, int>> ans;
  queue<pair<tuple<int, int, int>, vector<int>>> q;
  q.push(get_diameter(0, g, active_nodes));
  
  while (!q.empty()) {
    auto [t, nodes] = q.front();
    q.pop();
    ans.push_back(t);
    auto [len, u, v] = t;
    unordered_set<int> vis;
    for (int i = 0; i < SZ(nodes); i++) {
      int node = nodes[i];
      if (vis.count(node)) {
        continue;
      }
      vis.insert(node);
      if (active_nodes[node]) {
        auto [t2, nodes2] = get_diameter(node, g, active_nodes);
        q.push({t2, nodes2});
        for (auto &x : nodes2) {
          vis.insert(x);
        }
      }
    }
  }
  
  sort(ans.rbegin(), ans.rend());
  for (auto &[len, u, v] : ans) {
    cout << len << ' ' << u + 1 << ' ' << v + 1 << ' ';
  }
  cout << '\n';
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