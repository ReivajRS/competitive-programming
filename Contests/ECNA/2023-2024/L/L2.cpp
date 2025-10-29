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

struct Node {
  int x, y;
};

signed main() { __
  int n, m;
  cin >> n >> m;

  vector<Node> nodes(n);

  FOR (i, 0, n) {
    int x, y;
    cin >> x >> y;
    nodes[i].x = x;
    nodes[i].y = y;
  }

  vector<list<pi>> g(n, list<pi>());

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

  /*
    dir
    0: up
    1: right
    2: down
    3: left
  */

  vector<vi> vis(n, vi(4, 0));
  vector<vi> cnt(n, vi(n, 0));
  stack<pi> st;

  auto decrement_edge = [&](int u, int v, int dec = 1) {
    for (auto it = g[u].begin(); it != g[u].end(); it++) {
      if (it->first != v)
        continue;
      it->second -= dec;
      if (!it->second) {
        g[u].erase(it);
      }
      break;
    }
    for (auto it = g[v].begin(); it != g[v].end(); it++) {
      if (it->first != u)
        continue;
      it->second -= dec;
      if (!it->second)
        g[v].erase(it);
      break;
    }
  };

  auto dfs = [&](auto &dfs, int u, int dir) -> bool {
    vis[u][dir] = 1;
    st.push({u, dir});

    int to_l = -1, to_m = -1, to_r = -1;
    if (dir == 0) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].x < nodes[u].x)
          to_l = v;
        else if (nodes[v].y > nodes[u].y)
          to_m = v;
        else if (nodes[v].x > nodes[u].x)
          to_r = v;
      }
    }
    else if (dir == 1) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].y > nodes[u].y)
          to_l = v;
        else if (nodes[v].x > nodes[u].x)
          to_m = v;
        else if (nodes[v].y < nodes[u].y)
          to_r = v;
      }
    }
    else if (dir == 2) {
      for (auto [v, k] : g[u]) {
        if (nodes[v].x > nodes[u].x)
          to_l = v;
        else if (nodes[v].y < nodes[u].y)
          to_m = v;
        else if (nodes[v].x < nodes[u].x)
          to_r = v;
      }
    }
    else {
      for (auto [v, k] : g[u]) {
        if (nodes[v].y < nodes[u].y)
          to_l = v;
        else if (nodes[v].x < nodes[u].x)
          to_m = v;
        else if (nodes[v].y > nodes[u].y)
          to_r = v;
      }
    }

    int nxtdir = 0, ldir = (dir - 1 + 4) % 4, rdir = (dir + 1) % 4;
    vi ops = {to_l, to_m, to_r}, dirs = {ldir, dir, rdir};
    int ways = (to_m != -1) + (to_l != -1) + (to_r != -1);

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
        }
        else {
          for (auto it = g[u].begin(); it != g[u].end(); it++) {
            if (it->first == to) {
              if (it->second & 1) {
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
    FOR (i, 0, SZ(path) - 1) {
      int u = path[i].first, v = path[i + 1].first;
      if (st.count({min(u, v), max(u, v)}))
        continue;
      decrement_edge(u, v, mn_k);
      st.insert({min(u, v), max(u, v)});
      cnt[u][v] = 0;
      cnt[v][u] = 0;
    }
  };

  auto check_cycle = [&](int src, int dir, bool first_time) -> pi {
    vis.assign(n, vi(4, 0));
    while (!st.empty())
      st.pop();
    
    if (first_time) {
      int start;
      if (dir == 0) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].y > nodes[src].y)
            start = v;
        }
      }
      else if (dir == 1) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].x > nodes[src].x)
            start = v;
        }
      }
      else if (dir == 2) {
        for (auto [v, k] : g[src]) {
          if (nodes[v].y < nodes[src].y)
            start = v;
        }
      }
      else {
        for (auto [v, k] : g[src]) {
          if (nodes[v].x < nodes[src].x)
            start = v;
        }
      }
      vis[src][dir] = 1;
      decrement_edge(src, start);
      cnt[src][start]++;
      src = start;
    }

    pi ret = {-1, -1};
    vector<pi> path;

    bool has_cycle = dfs(dfs, src, dir);
    if (has_cycle) {
      while (!st.empty())
        path.pb(st.top()), st.pop();
      reverse(ALL(path));
      ret = path.back();
      reduce(path);
    }

    return ret;
  };

  int dir = 0;
  if (d == 'N') dir = 0;
  else if (d == 'E') dir = 1;
  else if (d == 'S') dir = 2;
  else dir = 3;

  s--;

  bool first_time = 1;

  while (s != -1) {
    pi ret = check_cycle(s, dir, first_time);
    s = ret.first;
    dir = ret.second;
    first_time = 0;
  }
  
  return 0;
}