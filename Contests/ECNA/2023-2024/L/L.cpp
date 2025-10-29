#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

struct Edge {
  int to, k;
  Edge() : to(-1), k(0) {}
};

struct Node {
  int x, y;
};

Node nodes[2501];

signed main() { __
  int n, m;
  cin >> n >> m;

  FOR (i, 0, n) {
    int x, y;
    cin >> x >> y;
    nodes[i].x = x;
    nodes[i].y = y;
  }

  vector<vector<pi>> g(n, vector<pi>());

  FOR (i, 0, m) {
    int u, v, k;
    cin >> u >> v >> k;
    u--, v--;
    g[u].pb({v, k});
    g[v].pb({u, k});
  }

  int s;
  char d;
  cin >> s >> d;

  // if (n == 8 && m == 9 && s == 4 && d == 'E') {
  //   cout << 10 << ' ' << 10 << ENDL;
  //   return 0;
  // }

  /*
    dir
    0: up
    1: right
    2: down
    3: left
  */

  vector<vi> vis(n, vi(4, 0));
  unordered_map<int, unordered_map<int, int>> cnt;
  stack<pi> st;

  auto decrement_edge = [&](int u, int v, int dec = 1) {
    for (vector<pi>::iterator it = g[u].begin(); it != g[u].end(); it++) {
      auto [to, k] = *it;
      if (to != v)
        continue;
      it->second -= dec;
      if (!it->second) {
        // cerr << "camino de " << u << " a " << v << " borrado" << ENDL;
        g[u].erase(it);
      }
      break;
    }
    for (vector<pi>::iterator it = g[v].begin(); it != g[v].end(); it++) {
      auto [to, k] = *it;
      if (to != u)
        continue;
      it->second -= dec;
      if (!it->second)
        g[v].erase(it);
      break;
    }
  };

  auto dfs = [&](auto &dfs, int u, int dir) -> bool {
    // cerr << nodes[u].x << ' ' << nodes[u].y << ' ' << dir << ENDL;
    vis[u][dir] = 1;
    st.push({u, dir});

    Edge l, m, r;
    if (dir == 0) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].x < nodes[u].x)
          l.to = v, l.k = k;
        if (nodes[v].y > nodes[u].y)
          m.to = v, m.k = k;
        if (nodes[v].x > nodes[u].x)
          r.to = v, r.k = k;
      }
    }
    if (dir == 1) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].y > nodes[u].y)
          l.to = v, l.k = k;
        if (nodes[v].x > nodes[u].x)
          m.to = v, m.k = k;
        if (nodes[v].y < nodes[u].y)
          r.to = v, r.k = k;
      }
    }
    if (dir == 2) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].x > nodes[u].x)
          l.to = v, l.k = k;
        if (nodes[v].y < nodes[u].y)
          m.to = v, m.k = k;
        if (nodes[v].x < nodes[u].x)
          r.to = v, r.k = k;
      }
    }
    if (dir == 3) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].y < nodes[u].y)
          l.to = v, l.k = k;
        if (nodes[v].x < nodes[u].x)
          m.to = v, m.k = k;
        if (nodes[v].y > nodes[u].y)
          r.to = v, r.k = k;
      }
    }

    int nxtdir = 0;
    int ldir = (dir - 1 + 4) % 4, rdir = (dir + 1) % 4;
    int ways = 0;
    vi ops = {l.to, m.to, r.to};
    vi dirs = {ldir, dir, rdir};
    ways += (m.to != -1);
    ways += (l.to != -1);
    ways += (r.to != -1);

    int to = -1;
    if (ways == 3) {
      to = ops[1];
      nxtdir = dirs[1];
    }
    else if (ways > 0) {
      FOR (i, 0, 3) {
        if (ops[i] != -1) {
          to = ops[i];
          nxtdir = dirs[i];
          break;
        }
      }
    }

    if (ways > 0) {
      if (vis[to][nxtdir] == 1) {
        if (cnt[u][to] < 2) {
          st.push({to, nxtdir});
          decrement_edge(u, to);
        } else {
          FOR (i, 0, SZ(g[u])) {
            if (g[u][i].first == to) {
              if (g[u][i].second & 1) {
                st.push({to, nxtdir});
                decrement_edge(u, to);
              }
              break;
            }
          }
        }
        return true;
      }
      if (vis[to][nxtdir] == 0) {
        decrement_edge(u, to);
        cnt[u][to]++;
        cnt[to][u]++;
        return dfs(dfs, to, nxtdir);
      }
    }
    else {
      // cerr << "salida" << ENDL;
      cout << nodes[u].x << ' ' << nodes[u].y << ENDL;
    }

    vis[u][dir] = 2;
    st.pop();
    
    return false;
  };

  auto reduce = [&](vector<pi> &path) {
    set<pi> st;
    int mn_k = 1e9;
    FOR (i, 0, SZ(path) - 1) {
      int u = path[i].first, v = path[i + 1].first;
      for (auto [to, k] : g[u]) {
        if (to != v)
          continue;
        mn_k = min(mn_k, k);
        break;
      }
    }
    // cerr << "min: " << mn_k << ENDL;
    FOR (i, 0, SZ(path) - 1) {
      int u = path[i].first, v = path[i + 1].first;
      // if (flags[u][v])
      //   continue;
      if (st.count({min(u, v), max(u, v)}))
        continue;
      // flags[u][v] = 1;
      st.insert({min(u, v), max(u, v)});
      decrement_edge(u, v, mn_k);
    }
  };

  auto check_cycle = [&](int src, int dir, bool first_time) -> pi {
    vis.assign(n, vi(4, 0));
    cnt.clear();
    while (!st.empty())
      st.pop();

    int _src = src, _dir = dir;
    
    if (first_time) {
      // cerr << "dir: " << dir << ENDL;
      Edge start;
      if (dir == 0) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].y > nodes[src].y)
            start.to = v, start.k = k;
        }
      }
      if (dir == 1) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].x > nodes[src].x)
            start.to = v, start.k = k;
        }
      }
      if (dir == 2) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].y < nodes[src].y)
            start.to = v, start.k = k;
        }
      }
      if (dir == 3) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].x < nodes[src].x)
            start.to = v, start.k = k;
        }
      }
      vis[src][dir] = 1;
      decrement_edge(src, start.to);
      cnt[src][start.to]++;
      cnt[start.to][src]++;
      // predir[src] = dir;
      src = start.to;
    }

    pi ret = {-1, -1};
    vector<pi> path;
    // cout << "camino" << ENDL;

    // if (first_time)
    //   cout << nodes[_src].x << ' ' << nodes[_src].y << ' ' << _dir << ENDL;
    // if (g[src].empty()) {
    //   cout << nodes[src].x << ' ' << nodes[src].y << ENDL;
    //   return ret;
    // }

    bool has_cycle = dfs(dfs, src, dir);
    if (has_cycle) {
      // cerr << "hay ciclo " << ENDL;
      // int p = cycle_end;
      // while (p != -1 && p != cycle_start) {
      //   cerr << p << ENDL;
      //   path.pb({p, predir[p]});
      //   p = parent[p];
      // }


      while (!st.empty())
        path.pb(st.top()), st.pop();
      // if (first_time)
      //   path.pb({_src, _dir});
      // path.pb({cycle_start, predir[cycle_start]});
      reverse(ALL(path));
      // if (first_time && path[0] == path.back())
      //   path.pop_back();
      // path.pb({cycle_start, predir[cycle_start]});

      ret = path.back();
      path.pb(path.back());
      // ret = path[0] == path.back() ? path[SZ(path) - 2] : path.back();
      reduce(path);
      // cerr << "camino" << ENDL;
      // for (auto &x : path) {
      //   cerr << x.first << ' ' << x.second << ENDL;
      // }
      // cerr << "fin" << ENDL;
    }

    // cout << "fin" << ENDL;
    return ret;
  };

  int dir = 0;
  if (d == 'N') dir = 0;
  if (d == 'E') dir = 1;
  if (d == 'S') dir = 2;
  if (d == 'W') dir = 3;

  s--;

  bool first_time = 1;

  while (s != -1) {
    // cerr << s << ' ' << dir << ENDL;
    pi ret = check_cycle(s, dir, first_time);
    s = ret.first;
    dir = ret.second;
    first_time = 0;
  }
  
  return 0;
}