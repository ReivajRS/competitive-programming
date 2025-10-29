#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
int g[51][51];
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

int bfs(int x, int y) {
  queue<pi> q;
  vector<vi> dist(n, vi(m, -1));
  dist[x][y] = 0;
  q.push({x, y});

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    
    FOR (k, 0, 4) {
      int ni = i + dy[k], nj = j + dx[k];
      if (g[i][j] & (1 << k))
        continue;
      if (ni < 0 || ni == n || nj < 0 || nj == m) {
        return dist[i][j];
      }
      if (dist[ni][nj] != -1)
        continue;
      dist[ni][nj] = dist[i][j] + 1;
      q.push({ni, nj});
    }
  }

  return -1;
}

signed main() { __
  cin >> n >> m;

  int x, y;
  cin >> x >> y;

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      cin >> g[i][j];
    }
  }

  cout << bfs(x - 1, y - 1) << ENDL;

  return 0;
}