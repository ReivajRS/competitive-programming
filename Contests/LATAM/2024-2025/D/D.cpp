#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

pair<int, vector<int>> hopcroftKarp(vector<vector<int>>& g, int m) {
  int res = 0;
  vector<int> btoa(m, -1), A(SZ(g)), B(m), cur, next;
  auto dfs = [&](auto self, int a, int L) -> bool {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
      B[b] = 0;
      if (btoa[b] == -1 || self(self, btoa[b], L + 1)) return btoa[b] = a, 1;
    }
    return 0;
  };
  while (1) {
    fill(A.begin(), A.end(), 0);
    fill(B.begin(), B.end(), 0);
    cur.clear();
    for (int a : btoa) if(a != -1) A[a] = -1;
    for (int a = 0; a < SZ(g); a++) if(A[a] == 0) cur.push_back(a);
    for (int lay = 1;; lay++) {
      bool islast = 0;
      next.clear();
      for (int a : cur) for (int b : g[a]) {
        if (btoa[b] == -1) {
          B[b] = lay;
          islast = 1;
        }
        else if (btoa[b] != a && !B[b]) {
          B[b] = lay;
          next.push_back(btoa[b]);
        }
      }
      if (islast) break;
      if (next.empty()) return {res, btoa};
      for (int a : next) A[a] = lay;
      cur.swap(next);
    }
    for (int a = 0; a < SZ(g); a++) res += dfs(dfs, a, 0);
  }
}

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

  int clique_id = -1;
  vector<int> clique_num(n, -1);
  vector<vector<int>> clique_in(n);
  vector<vector<int>> g(n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (!mat[i][j]) continue;
      clique_id++;
      vector<int> clique = {i, j};
      for (int k = 0; k < n; k++) {
        if (!mat[i][k] || !mat[j][k]) continue;
        clique.push_back(k);
      }
      for (auto x : clique) {
        if (clique_num[x] != -1) {
          g[clique_id].push_back(clique_num[x]);
          g[clique_num[x]].push_back(clique_id);
        }
        else {
          clique_num[x] = clique_id;
        }
        clique_in[x].push_back(clique_id);
      }
      for (auto x : clique) {
        for (auto y : clique) {
          mat[x][y] = mat[y][x] = 0;
        }
      }
    }
  }

  vector<int> color(n, -1);
  auto dfs = [&](auto &dfs, int u, int c) -> void {
    color[u] = c;
    for (auto v : g[u]) {
      if (color[v] == -1) {
        dfs(dfs, v, c ^ 1);
      }
    }
  };

  for (int i = 0; i <= clique_id; i++) {
    if (color[i] == -1) {
      dfs(dfs, i, 0);
    }
  }

  for (int i = 0; i < n; i++) {
    while (SZ(clique_in[i]) < 2) {
      clique_in[i].push_back(++clique_id);
    }
  }

  vector<vector<int>> g2(2 * n);
  for (int i = 0; i < n; i++) {
    int u = clique_in[i][0], v = clique_in[i][1];
    if (color[u] == 1) {
      swap(u, v);
    }
    g2[u].push_back(v);
  }

  cout << hopcroftKarp(g2, 2 * n).first << '\n';

  return 0;
}