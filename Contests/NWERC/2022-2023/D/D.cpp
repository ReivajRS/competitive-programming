#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0);

using T = long double;
using VT = vector<T>;
using VVT = vector<VT>;
using VVVT = vector<VVT>;

constexpr int L = 10, HL = L / 2;
T C4 = acos(-1.0) * L / 4.0;
constexpr int di[] = {-1, 0, 1, 0}, dj[] = {0, 1, 0, -1};

signed main() { __
  int n, m;
  cin >> n >> m;
  vector<vi> t(n, vi(m));
  FOR (i, 0, n) {
    FOR (j, 0, m) {
      char c;
      cin >> c;
      t[i][j] = c != 'X';
    }
  }

  VVVT dbp(2, VVT(8, VT(8, 0)));
  FOR (i, 0, 8) {
    FOR (j, i, 8) {
      dbp[0][i][j] = dbp[0][j][i] = min(j - i, i + 8 - j) * HL;
    }
  }

  for (int i = 1; i < 8; i += 2) {
    for (int j = i; j < 8; j += 2) {
      T ds = min(j - i, i + 8 - j) / 2;
      dbp[1][i][j] = dbp[1][j][i] = ds * C4;
    }
  }

  FOR (i, 0, 8) {
    FOR (j, i, 8) {
      if ((i == j) || (i % 2 + j % 2 == 2)) {
        continue;
      }

      T d = 0;
      int ii = i;
      if (ii % 2 == 0) {
        d += HL;
        ii++;
      }
      
      int jj = j;
      if (jj % 2 == 0) {
        d += HL;
        jj--;
      }

      d += dbp[1][ii][jj];
      dbp[1][i][j] = dbp[1][j][i] = d;

      d = 0;
      ii = i;
      if (ii % 2 == 0) {
        d += HL;
        ii = (ii + 7) % 8;
      }
      
      jj = j;
      if (jj % 2 == 0) {
        d += HL;
        jj++;
      }

      d += dbp[1][ii][jj];
      dbp[1][i][j] = dbp[1][j][i] = min(dbp[1][i][j], d);
    }
  }

  vector<vector<pi>> adj(8);
  adj[0] = {{3, 2}, {0, 6}};
  adj[1] = {{0, 5}};
  adj[2] = {{0, 4}, {1, 0}};
  adj[3] = {{1, 7}};
  adj[4] = {{1, 6}, {2, 2}};
  adj[5] = {{2, 1}};
  adj[6] = {{2, 0}, {3, 4}};
  adj[7] = {{3, 3}};

  VVVT dist(n, VVT(m, VT(8, 1e18)));
  dist[0][0][0] = 0;
  priority_queue<tuple<T, int, int, int>> pq;
  pq.push({0, 0, 0, 0});
  while (!pq.empty()) {
    auto [d, i, j, p] = pq.top();
    pq.pop();
    d = -d;
    if (dist[i][j][p] < d) {
      continue;
    }

    // intentar moverse a todos los demas puntos de la casilla
    FOR (k, 0, 8) {
      if (p == k) {
        continue;
      }

      T dd = d + dbp[t[i][j]][p][k];
      if (dist[i][j][k] > dd) {
        dist[i][j][k] = dd;
        pq.push({-dd, i, j, k});
      }
    }

    // moverse a todos los adyacentes posibles, de otras casillas
    for (auto &[dir, pp] : adj[p]) {
      int ii = i + di[dir], jj = j + dj[dir];
      if (ii >= 0 && ii < n && jj >= 0 && jj < m && dist[ii][jj][pp] > d) {
        dist[ii][jj][pp] = d;
        pq.push({-d, ii, jj, pp});
      }
    }
  }
  cout << setprecision(12) << fixed << dist[n - 1][m - 1][4] << ENDL;

  return 0;
}