#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)
#define ENDL '\n'

bool vis[10][10][10][10];

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<string> mat(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }

  int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
  int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

  auto is_valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < n;
  };

  auto get_val = [&]() -> int {
    memset(vis, 0, sizeof vis);
    int up = 0;
    int adj = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == '.') continue;
        if (mat[i][j] == 'P') {
          up++;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'M' && !vis[i][j][ii][jj]) {
              adj++;
              vis[i][j][ii][jj] = 1;
              vis[ii][jj][i][j] = 1;
            }
          }
        }
        if (mat[i][j] == 'M') {
          up++;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'P' && !vis[i][j][ii][jj]) {
              adj++;
              vis[i][j][ii][jj] = 1;
              vis[ii][jj][i][j] = 1;
            }
          }
        }
        if (mat[i][j] == 'O') {
          up++;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'O' && !vis[i][j][ii][jj]) {
              adj++;
              vis[i][j][ii][jj] = 1;
              vis[ii][jj][i][j] = 1;
            }
          }
        }
      }
    }
    return up + adj;
  };


  auto get_best = [&]() -> pair<int, pair<int, int>> {
    pair<int, pair<int, int>> mx = {1, {-1, -1}};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == '.') continue;
        if (mat[i][j] == 'p') {
          int val = 1;
          int adj = 0;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'M') {
              adj++;
            }
          }
          mx = max(mx, {val + adj, {i, j}});
        }
        if (mat[i][j] == 'm') {
          int val = 1;
          int adj = 0;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'P') {
              adj++;
            }
          }
          mx = max(mx, {val + adj, {i, j}});
        }
        if (mat[i][j] == 'o') {
          int val = 1;
          int adj = 0;
          for (int k = 0; k < 8; k++) {
            int ii = i + dy[k], jj = j + dx[k];
            if (!is_valid(ii, jj)) continue;
            if (mat[ii][jj] == 'O') {
              adj++;
            }
          }
          mx = max(mx, {val + adj, {i, j}});
        }
      }
    }
    return mx;
  };

  int val1 = get_val();

  while (1) {
    pair<int, pair<int, int>> mx = get_best();
    // cout << mx.first << ' ' << mx.second.first << ' ' << mx.second.second << '\n';
    if (mx.first == 1) break;
    auto [i, j] = mx.second;
    mat[i][j] = toupper(mat[i][j]);
  }

  int val2 = get_val();

  cout << val1 << ' ' << val2 << '\n';

  for (int i = 0; i < n; i++) {
    cout << mat[i] << '\n';
  }

  return 0;
}