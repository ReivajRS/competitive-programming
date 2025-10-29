#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; i++)

template<typename T>
struct Dinic {
  #define INF numeric_limits<T>::max()
  struct Edge {
    int to, rev;
    T c, oc;
    T flow() {
      return max(oc - c, T(0));
    }
  };
  vector<int> lvl, ptr, q;
  vector<vector<Edge>> adj;
  Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
  void addEdge(int a, int b, T c, T rcap = 0) {
    adj[a].push_back({b, SZ(adj[b]), c, c});
    adj[b].push_back({a, SZ(adj[a]) - 1, rcap, rcap});
  }
  T dfs(int v, int t, T f) {
    if (v == t || !f) return f;
    for (int& i = ptr[v]; i < SZ(adj[v]); i++) {
      Edge& e = adj[v][i];
      if (lvl[e.to] == lvl[v] + 1) if (T p = dfs(e.to, t, min(f, e.c))) {
        e.c -= p, adj[e.to][e.rev].c += p;
        return p;
      }
    }
    return 0;
  }
  T calc(int s, int t) {
    T flow = 0;
    q[0] = s;
    for (int L = 0; L < 31; L++) do {
      lvl = ptr = vector<int>(SZ(q));
      int qi = 0, qe = lvl[s] = 1;
      while (qi < qe && !lvl[t]) {
        int v = q[qi++];
        for (Edge e : adj[v]) {
          if (!lvl[e.to] && e.c >> (30 - L)) {
            q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
          }
        }
      }
      while (T p = dfs(s, t, INF)) flow += p;
    }
    while (lvl[t]);
    return flow;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edges[i] = {u, v};
  }

  auto check = [&](int x) -> bool {
    Dinic<int> mf(m + n + 2);
    int s = m + n, t = m + n + 1;
    for (int i = 0; i < m; i++) {
      mf.addEdge(s, i, 1);
    }
    for (int i = 0; i < m; i++) {
      auto [u, v] = edges[i];
      mf.addEdge(i, u + m, 1);
      mf.addEdge(i, v + m, 1);
    }
    for (int i = 0; i < n; i++) {
      mf.addEdge(i + m, t, x);
    }
    return mf.calc(s, t) == m;
  };

  int l = 0, r = m;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    }
    else {
      l = mid + 1;
    }
  }

  cout << l << '\n';

  Dinic<int> mf(m + n + 2);
  int s = m + n, t = m + n + 1;
  for (int i = 0; i < m; i++) {
    mf.addEdge(s, i, 1);
  }
  for (int i = 0; i < m; i++) {
    auto [u, v] = edges[i];
    mf.addEdge(i, u + m, 1);
    mf.addEdge(i, v + m, 1);
  }
  for (int i = 0; i < n; i++) {
    mf.addEdge(i + m, t, l);
  }

  mf.calc(s, t);

  for (int i = 0; i < m; i++) {
    for (auto edge : mf.adj[i]) {
      auto [to, rev, c, rc] = edge;
      if (to >= m && to < n + m && edge.flow() == 1) {
        auto [u, v] = edges[i];
        if (to == u + m) {
          cout << u + 1 << ' ' << v + 1 << '\n';
        }
        else {
          cout << v + 1 << ' ' << u + 1 << '\n';
        }
        break;
      }
    }
  }
  
  return 0;
}