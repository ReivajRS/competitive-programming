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

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  vector<vi> actors(n + 1), movies(m + 1);
  vector<vi> adj(n + 1, vi(n + 1, -1));
  vector<vi> g(n + 1);

  FOR (i, 0, n) {
    int x;
    cin >> x;
    while (x--) {
      int y;
      cin >> y;
      y--;
      actors[i].pb(y);
      movies[y].pb(i);
    }
  }

  FOR (u, 0, n) {
    unordered_set<int> actors_in;
    for (auto &x : actors[u]) {
      actors_in.insert(x);
    }
    FOR (v, 0, n) {
      bool flag = 0;
      for (auto &y : actors[v]) {
        if (actors_in.count(y)) {
          flag = 1;
          adj[u][v] = y;
          adj[v][u] = y;
          g[u].pb(v);
          g[v].pb(u);
          break;
        }
        if (flag) break;
      }
    }
  }

  auto get_path = [](auto self, int u, vi& parent, vi& path) -> void {
    if (u == -1) return;
    self(self, parent[u], parent, path);
    path.pb(u);
  };

  auto solve = [&](int src, int dest) -> void {
    FOR (i, 0, SZ(movies[src])) {
      vi dist(n + 1, -1);
      vi parent(n + 1, -1);
      queue<int> q;
      q.push(movies[src][i]);
      dist[movies[src][i]] = 0;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) if (dist[v] == -1) {
          q.push(v);
          dist[v] = dist[u] + 1;
          parent[v] = u;
        }
      }
      FOR (j, 0, SZ(movies[dest])) {
        if (dist[movies[dest][j]] != -1) {
          vi path;
          get_path(get_path, movies[dest][j], parent, path);
          cout << SZ(path) + 1 << ENDL;
          cout << src + 1 << ' ';
          cout << path[0] + 1 << ' ';
          FOR (k, 1, SZ(path)) {
            cout << adj[path[k - 1]][path[k]] + 1 << ' ' << path[k] + 1 << ' ';
          }
          cout << dest + 1 << ENDL;
          return;
        }
      }
    }
    cout << -1 << ENDL;
  };

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    solve(u, v);
  }
  
  return 0;
}