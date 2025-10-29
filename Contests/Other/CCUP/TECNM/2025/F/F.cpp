#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;
  
  vector<string> g(n);
  for (int i = 0; i < n; i++) {
    cin >> g[i];
  }

  map<char, int> dir;
  dir['^'] = 0;
  dir['>'] = 1;
  dir['v'] = 2;
  dir['<'] = 3;

  int dx[] = {0, 1, 0, -1};
  int dy[] = {-1, 0, 1, 0};

  deque<pair<int, int>> dq;
  vector<vector<int>> dist(n, vector<int>(m, int(1e9)));

  dist[0][0] = 0;
  dq.push_back({0, 0});

  while (!dq.empty()) {
    auto [i, j] = dq.front();
    dq.pop_front();
    for (int k = 0; k < 4; k++) {
      int ii = i + dy[k], jj = j + dx[k];
      if (ii < 0 || ii >= n || jj < 0 || jj >= m) {
        continue;
      }
      int cost = dir[g[i][j]] != k;
      if (dist[i][j] + cost < dist[ii][jj]) {
        dist[ii][jj] = dist[i][j] + cost;
        if (cost == 0) {
          dq.push_front({ii, jj});
        }
        else {
          dq.push_back({ii, jj});
        }
      }
    }
  }

  cout << dist[n - 1][m - 1] << '\n';
}