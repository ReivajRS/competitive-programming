#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  queue<pair<int, int>> q;
  q.push({0, 0});

  vector<vector<int>> dist(n, vector<int>(n, -1));
  dist[0][0] = 0;

  vector<int> dx = {-1, 1, 2, 2, 1, -1, -2, -2};
  vector<int> dy = {-2, -2, -1, 1, 2, 2, 1, -1};

  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();
    for (int k = 0; k < 8; k++) {
      int ii = i + dy[k], jj = j + dx[k];
      if (ii >= 0 && ii < n && jj >= 0 && jj < n && dist[ii][jj] == -1) {
        dist[ii][jj] = dist[i][j] + 1;
        q.push({ii, jj});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << dist[i][j] << ' ';
    }
    cout << '\n';
  }
}