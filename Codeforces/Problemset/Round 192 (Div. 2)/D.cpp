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

int dx[] = {0, 0, 1, -1}, dy[] = {1, -1, 0, 0};

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n, m;
  cin >> n >> m;

  pi s, e;
  vector<string> mat(n);
  FOR (i, 0, n) {
    cin >> mat[i];
    FOR (j, 0, m) {
      if (mat[i][j] == 'S') s = {i, j};
      if (mat[i][j] == 'E') e = {i, j};
    }
  }

  queue<pi> q;
  vector<vi> dist(n, vi(m, 1e8));
  dist[e.first][e.second] = 0;
  q.push(e);

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    FOR (k, 0, 4) {
      int ii = i + dy[k], jj = j + dx[k];
      if (ii < 0 || ii >= n || jj < 0 || jj >= m || mat[ii][jj] == 'T' || dist[ii][jj] != 1e8) {
        continue;
      }
      dist[ii][jj] = dist[i][j] + 1;
      q.push({ii, jj});
    }
  }

  int d = dist[s.first][s.second];
  int ans = 0;

  FOR (i, 0, n) {
    FOR (j, 0, m) {
      if (!isdigit(mat[i][j])) {
        continue;
      }
      if (dist[i][j] <= d) {
        ans += mat[i][j] - '0';
      }
    }
  }

  cout << ans << ENDL;
  
  return 0;
}