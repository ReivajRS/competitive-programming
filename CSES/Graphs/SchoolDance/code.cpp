#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

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
    if (pushed == 0) {
      return 0;
    }
    if (u == t) {
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

  ll max_flow() {
    ll flow = 0;
    while (true) {
      level.assign(n, -1);
      level[s] = 0;
      q.push(s);
      if (!bfs()) {
        break;
      }
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

  int n, m, k;
  cin >> n >> m >> k;

  int s = n + m, t = s + 1;

  Dinic dinic(n + m + 2, s, t);

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    dinic.addEdge(a - 1, n + b - 1, 1);
  }
  for (int i = 0; i < n; i++) {
    dinic.addEdge(s, i, 1);
  }
  for (int i = 0; i < m; i++) {
    dinic.addEdge(n + i, t, 1);
  }

  cout << dinic.max_flow() << '\n';
  for (auto edge : dinic.edges) { 
    int u = edge.u, v = edge.v;
    if (u < s && v < s && edge.flow == 1) {
      cout << u + 1 << ' ' << v - n + 1 << '\n';
    }
  }
  
  return 0;
}