#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Dinic {
  struct Edge {
    int u, v;
    ll cap, flow;
    Edge(int u, int v, ll cap) : u(u), v(v), cap(cap), flow(0) {}
  };
  
  static const ll INF = 1e18;
  int n, s, t, cnt_edges;
  vector<Edge> edges;
  vector<vector<int>> g;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t), cnt_edges(0), g(n), level(n), ptr(n) {}

  void addEdge(int u, int v, ll cap) {
    edges.emplace_back(u, v, cap);
    edges.emplace_back(v, u, 0);
    g[u].push_back(cnt_edges++);
    g[v].push_back(cnt_edges++);
  }

  bool bfs() {
    level.assign(n, -1);
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto id : g[u]) {
        if (edges[id].cap == edges[id].flow) {
          continue;
        }
        int v = edges[id].v;
        if (level[v] != -1) {
          continue;
        }
        level[v] = level[u] + 1;
        q.push(v);
      }
    }
    return level[t] != -1;
  }

  ll dfs(int u, ll pushed) {
    if (u == t || pushed == 0) {
      return pushed;
    }
    for (int& cid = ptr[u]; cid < (int)g[u].size(); cid++) {
      int id = g[u][cid];
      int v = edges[id].v;
      if (level[u] + 1 != level[v]) {
        continue;
      }
      ll rem = edges[id].cap - edges[id].flow;
      ll flow = dfs(v, min(pushed, rem));
      if (flow == 0) {
        continue;
      }
      edges[id].flow += flow;
      edges[id ^ 1].flow -= flow;
      return flow;
    }
    return 0;
  }

  ll calc() {
    ll flow = 0;
    while (bfs()) {
      ptr.assign(n, 0);
      ll pushed = 0;
      while ((pushed = dfs(s, INF)) > 0) {
        flow += pushed;
      }
    }
    return flow;
  }

  bool leftOfMinCut(int u) {
    return level[u] != -1;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  int s = 2 * n, t = s + 1;

  Dinic dinic(2 * n + 2, s, t);

  vector<vector<int>> g(2 * n);

  for (int i = 0; i < n; i++) {
    dinic.addEdge(s, i, 1);
    dinic.addEdge(i + n, t, 1);
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      if (c == 'o') {
        dinic.addEdge(i, j + n, 1);
        g[i].push_back(j + n);
        g[j + n].push_back(i);
      }
    }
  }

  cout << dinic.calc() << '\n';

  vector<int> c(2 * n, -1);
  for (auto [u, v, cap, flow] : dinic.edges) {
    if (u < n && v < n + n && flow == 1) {
      c[u] = v;
      c[v] = u;
    }
  }

  vector<bool> vis(2 * n);
  auto dfs = [&](auto& dfs, int u) -> void {
    vis[u] = true;
    if (u >= n && !vis[c[u]]) {
      dfs(dfs, c[u]);
    }
    else {
      for (auto& v : g[u]) {
        if (c[u] != v && !vis[v]) {
          dfs(dfs, v);
        }
      }
    }
  };

  for (int i = 0; i < n; i++) {
    if (c[i] == -1 && !vis[i]) {
      dfs(dfs, i);
    }
  }

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << 1 << ' ' << i + 1 << '\n';
    }
    if (vis[i + n]) {
      cout << 2 << ' ' << i + 1 << '\n';
    }
  }

  return 0;
}