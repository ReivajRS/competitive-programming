#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> mat(n, vector<int>(n, -1));
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  int cnt = n * n - 1, dir = 0;
  auto dfs = [&](auto& dfs, int i, int j) -> void {
    mat[i][j] = cnt--;
    int ii = i + dy[dir], jj = j + dx[dir];
    if (ii < 0 || ii >= n || jj < 0 || jj >= n || mat[ii][jj] != -1) {
      dir = (dir + 1) % 4;
      ii = i + dy[dir], jj = j + dx[dir];
    }
    if (ii < 0 || ii == n || jj < 0 || jj == n || mat[ii][jj] != -1) {
      return;
    }
    dfs(dfs, ii, jj);
  };
  dfs(dfs, 0, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << mat[i][j] << ' ';
    }
    cout << '\n';
  }
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}