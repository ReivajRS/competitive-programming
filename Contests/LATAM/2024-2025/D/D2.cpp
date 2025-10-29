#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

template<typename T>
 struct PushRelabel {
   struct Edge {
     int dest, back;
     T f, c;
   };
   vector<vector<Edge>> g;
   vector<T> ec;
   vector<Edge*> cur;
   vector<vector<int>> hs;
   vector<int> H;
   PushRelabel(int n) : g(n), ec(n), cur(n), hs(2 * n), H(n) {}
   void addEdge(int s, int t, T cap, T rcap = 0) {
     if (s == t) return;
     g[s].push_back({t, SZ(g[t]), 0, cap});
     g[t].push_back({s, SZ(g[s]) - 1, 0, rcap});
   }
   void addFlow(Edge& e, T f) {
     Edge& back = g[e.dest][e.back];
     if (!ec[e.dest] && f) hs[H[e.dest]].push_back(e.dest);
     e.f += f;
     e.c -= f;
     ec[e.dest] += f;
     back.f -= f;
     back.c += f;
     ec[back.dest] -= f;
   }
   T calc(int s, int t) {
     int v = SZ(g);
     H[s] = v;
     ec[t] = 1;
     vector<int> co(2 * v);
     co[0] = v - 1;
     for (int i = 0; i < v; i++) cur[i] = g[i].data();
     for (Edge& e : g[s]) addFlow(e, e.c);
     for (int hi = 0;;) {
       while (hs[hi].empty()) if (!hi--) return -ec[s];
       int u = hs[hi].back();
       hs[hi].pop_back();
       while (ec[u] > 0) if (cur[u] == g[u].data() + SZ(g[u])) { // discharge u
         H[u] = 1e9;
         for (Edge& e : g[u]) if (e.c && H[u] > H[e.dest] + 1) H[u] = H[e.dest] + 1, cur[u] = &e;
         if (++co[H[u]], !--co[hi] && hi < v) for (int i = 0; i < v; i++) if (hi < H[i] && H[i] < v)-- co[H[i]], H[i] = v + 1;
         hi = H[u];
       } 
       else if (cur[u]->c && H[u] == H[cur[u]->dest] + 1) addFlow(*cur[u], min(ec[u], cur[u]->c));
       else ++cur[u];
     }
   }
   bool leftOfMinCut(int a) { return H[a] >= SZ(g); }
 };

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<vector<bool>> mat(n, vector<bool>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char c;
      cin >> c;
      mat[i][j] = c == '1';
    }
  }

  vector<vector<int>> clique;
  vector<int> clique_num(n, -1);
  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!mat[i][j]) continue;
      clique.push_back({i, j});
      for (int k = 0; k < n; k++) {
        if (!mat[i][k] || !mat[j][k]) continue;
        clique.back().push_back(k);
      }
      int clique_id = SZ(clique) - 1;
      for (auto x : clique.back()) {
        if (clique_num[x] != -1) {
          g[clique_id].push_back(clique_num[x]);
          g[clique_num[x]].push_back(clique_id);
        }
        else {
          clique_num[x] = clique_id;
        }
      }
      for (auto x : clique.back()) {
        for (auto y : clique.back()) {
          mat[x][y] = mat[y][x] = 0;
        }
      }
    }
  }

  vector<int> color(n, -1);
  vector<vector<int>> clique_in(n, {-1, -1});
  auto dfs = [&](auto &dfs, int u, int c) -> void {
    color[u] = c;
    for (auto x : clique[u]) {
      clique_in[x][c] = u;
    }
    for (auto v : g[u]) {
      if (color[v] == -1) {
        dfs(dfs, v, c ^ 1);
      }
    }
  };

  int clique_cnt = SZ(clique);
  for (int i = 0; i < clique_cnt; i++) {
    if (color[i] == -1) {
      dfs(dfs, i, 0);
    }
  }

  for (int i = 0; i < n; i++) {
    if (clique_in[i][0] == -1) {
      clique_in[i][0] = clique_cnt++;
    }
    if (clique_in[i][1] == -1) {
      clique_in[i][1] = clique_cnt++;
    }
  }

  PushRelabel<int> mf(2 * clique_cnt + 2);
  int s = 2 * clique_cnt, t = 2 * clique_cnt + 1;
  
  for (int i = 0; i < clique_cnt; i++) {
    mf.addEdge(s, i, 1);
  }
  for (int i = 0; i < n; i++) {
    mf.addEdge(clique_in[i][0], clique_in[i][1] + clique_cnt, 1);
  }
  for (int i = 0; i < clique_cnt; i++) {
    mf.addEdge(i + clique_cnt, t, 1);
  }

  cout << mf.calc(s, t) << '\n';

  return 0;
}