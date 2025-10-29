#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

struct DSU {
  vi e;
  void init(int n) { e = vi(n, -1); }
  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }
  bool join(int a, int b) {
    a = get(a), b = get(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b];
    e[b] = a;
    return true;
  }
};

vector<tuple<int, int, int, int>> edges;
set<tuple<int, int, int, int>> mst, mst_o;
vector<tuple<int, int, int>> g[2001];

bool dfs(int u, int p, int& dest, tuple<int, int, int, int>& edge) {
  if (u == dest) return true;
  bool has_path = false;
  for (auto [v, w, i] : g[u]) if (v != p) {
    if (dfs(v, u, dest, edge)) {
      has_path = true;
      edge = max(edge, {w, u, v, i});
    }
  }
  return has_path;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  FOR (i, 0, m) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges.pb({w, i, u, v});
    if (i < n - 1) {
      mst_o.insert({u, v, w, i});
      g[u].pb({v, w, i});
      g[v].pb({u, w, i});
    }
  }

  sort(ALL(edges));

  DSU dsu;
  dsu.init(n);

  for (auto [w, i, u, v] : edges) {
    if (dsu.join(u, v)) {
      mst.insert({u, v, w, i});
    }
  }

  vector<pi> ans;

  for (auto [u, v, w, i] : mst) {
    if (mst_o.count({u, v, w, i})) continue;

    g[u].pb({v, w, i});
    g[v].pb({u, w, i});

    tuple<int, int, int, int> edge = {-1, -1, -1, -1};
    dfs(u, -1, v, edge);
    auto [w2, u2, v2, i2] = edge;

    for (vector<tuple<int, int, int>>::iterator it = g[u2].begin(); it != g[u2].end(); it++) {
      if (get<2>(*it) == i2) {
        g[u2].erase(it);
        break;
      }
    }
    for (vector<tuple<int, int, int>>::iterator it = g[v2].begin(); it != g[v2].end(); it++) {
      if (get<2>(*it) == i2) {
        g[v2].erase(it);
        break;
      }
    }

    ans.pb({i2, i});
  }

  cout << SZ(ans) << ENDL;
  for (auto [u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << ENDL;
  }
  cout << ENDL;
  
  return 0;
}