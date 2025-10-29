#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) (int(x.size()))

constexpr int INF = 1e9;

constexpr pair<int, int> D[4] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, r, c, x, y;
  cin >> n >> m >> r >> c >> x >> y;
  --r, --c;

  vector<string> maze(n);
  for (int i = 0; i < n; ++i) {
    cin >> maze[i];
  }

  vector<vector<int>> leftSteps(n, vector<int>(m, 2e9));
  deque<pair<int, int>> dq;
  leftSteps[r][c] = 0;
  dq.emplace_front(r, c);
  while (!dq.empty()) {
    auto [i, j] = dq.front();
    dq.pop_front();
    for (int dir = 0; dir < 4; ++dir) {
      auto [DI, DJ] = D[dir];
      int ii = i + DI, jj = j + DJ;
      if (ii == -1 || ii == n || jj == -1 || jj == m || maze[ii][jj] == '*') {
        continue;
      }
      int steps = leftSteps[i][j];
      if (!dir && steps + 1 < leftSteps[ii][jj]) {
        leftSteps[ii][jj] = steps + 1;
        dq.emplace_back(ii, jj);
      } else if (dir && steps < leftSteps[ii][jj]) {
        leftSteps[ii][jj] = steps;
        dq.emplace_front(ii, jj);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (leftSteps[i][j] > x) {
        continue;
      }
      int right;
      if (j <= c) {
        right = leftSteps[i][j] - (c - j);
      } else {
        right = j - c + leftSteps[i][j];
      }
      ans += right <= y;
    }
  }
  cout << ans << '\n';

  return 0;
}