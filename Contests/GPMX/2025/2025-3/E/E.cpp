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
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, k, m;
  cin >> n >> k >> m;

  vector<vector<int>> C(n, vector<int>(k));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      cin >> C[i][j];
    }
  }

  vector<vector<int>> id_in(n, vector<int>(k)), id_out(n, vector<int>(k));

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      id_in[i][j] = cnt++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      id_out[i][j] = cnt++;
    }
  }

  int s = cnt++, t = cnt++;
  Dinic mf(cnt, s, t);

  constexpr int MAX = int(2e9);

  for (int i = 0; i < m; i++) {
    int f, u, v;
    cin >> f >> u >> v;
    f--, u--, v--;
    mf.addEdge(id_out[f][u], id_in[f + 1][v], MAX);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      mf.addEdge(id_in[i][j], id_out[i][j], C[i][j]);
    }
  }

  for (int j = 0; j < k; j++) {
    mf.addEdge(s, id_in[0][j], MAX);
  }

  ll flow = 0;
  vector<ll> ans(n);

  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < k; j++) {
      mf.addEdge(id_out[i][j], t, MAX);
    }
    flow += mf.max_flow();
    ans[i] = flow;
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';

  return 0;
}