#include <bits/stdc++.h>
using namespace std;

struct DSU {
  vector<int> e;
  DSU(int n) : e(n, -1) {}
  int get(int x) {
    return e[x] < 0 ? x : e[x] = get(e[x]);
  }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, Q;
  cin >> n >> Q;
  
  DSU dsu(n);
  vector<int> g(n);
  vector<vector<int>> gr(n);
  vector<vector<int>> succ(n, vector<int>(30));
  for (int i = 0; i < n; i++) {
    cin >> g[i];
    g[i]--;
    gr[g[i]].push_back(i);
    succ[i][0] = g[i];
    dsu.join(i, g[i]);
  }

  for (int k = 1; k < 30; k++) {
    for (int i = 0; i < n; i++) {
      succ[i][k] = succ[succ[i][k - 1]][k - 1];
    }
  }

  vector<int> vis(n, -1);
  vector<int> dist_cycle(n, -1), cycle_index(n, -1), cycle_len(n, -1);
  int cycle_start = -1, cycle_end = -1;
  auto dfs = [&](auto& dfs, int u, int& cnt) -> void {
    vis[u] = cnt;
    int v = g[u];
    if (vis[v] != -1) {
      if (vis[v] == cnt) {
        cycle_start = v;
        cycle_end = u;
      }
      return;
    }
    dfs(dfs, v, cnt);
  };
  
  int cnt = 0;
  queue<int> q;
  for (int i = 0; i < n; i++) {
    if (vis[i] == -1) {
      cycle_start = -1;
      cycle_end = -1;
      dfs(dfs, i, cnt);
      cnt++;
      if (cycle_start == -1) {
        continue;
      }
      int len = 1;
      int idx = 0;
      dist_cycle[cycle_start] = 0;
      cycle_index[cycle_start] = idx++;
      q.push(cycle_start);
      for (int u = g[cycle_start]; u != cycle_start; u = g[u]) {
        dist_cycle[u] = 0;
        cycle_index[u] = idx++;
        len++;
        q.push(u);
      }
      cycle_len[cycle_start] = len;
      for (int u = g[cycle_start]; u != cycle_start; u = g[u]) {
        cycle_len[u] = len;
      }
    }
  }

  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto& v : gr[u]) {
      if (dist_cycle[v] == -1) {
        dist_cycle[v] = dist_cycle[u] + 1;
        q.push(v);
      }
    }
  }

  while (Q--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    if (dsu.get(a) != dsu.get(b)) {
      cout << -1 << '\n';
      continue;
    }
    if (dist_cycle[a] != 0 && dist_cycle[b] != 0) {
      if (dist_cycle[a] < dist_cycle[b]) {
        cout << -1 << '\n';
        continue;
      }
      int diff_ori = dist_cycle[a] - dist_cycle[b];
      int diff = dist_cycle[a] - dist_cycle[b];
      for (int k = 29; k >= 0; k--) {
        if (diff & (1 << k)) {
          diff ^= (1 << k);
          a = succ[a][k];
        }
      }
      if (a == b) {
        cout << diff_ori<< '\n';
      }
      else {
        cout << -1 << '\n';
      }
      continue;
    }
    if (dist_cycle[a] == 0 && dist_cycle[b] == 0) {
      int dist_in_cycle;
      if (cycle_index[a] <= cycle_index[b]) {
        dist_in_cycle = cycle_index[b] - cycle_index[a];
      }
      else {
        dist_in_cycle = cycle_len[a] - (cycle_index[a] - cycle_index[b]);
      }
      cout << dist_in_cycle << '\n';
      continue;
    }
    if (dist_cycle[a] == 0 && dist_cycle[b] != 0) {
      cout << -1 << '\n';
      continue;
    }
    int dist_ori = dist_cycle[a];
    int dist = dist_cycle[a];
    for (int k = 29; k >= 0; k--) {
      if (dist & (1 << k)) {
        dist ^= (1 << k);
        a = succ[a][k];
      }
    }
    int dist_in_cycle;
    if (cycle_index[a] <= cycle_index[b]) {
      dist_in_cycle = cycle_index[b] - cycle_index[a];
    }
    else {
      dist_in_cycle = cycle_len[a] - (cycle_index[a] - cycle_index[b]);
    }
    cout << dist_ori + dist_in_cycle << '\n';
  }
  
  return 0;
}