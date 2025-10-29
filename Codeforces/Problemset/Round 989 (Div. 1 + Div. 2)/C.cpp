#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> mat(n);
  
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }

  vector<vector<int>> vis(n, vector<int>(m));

  // D, R, U, L
  vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};

  map<char, int> mp_rev;
  mp_rev['U'] = 0;
  mp_rev['L'] = 1;
  mp_rev['D'] = 2;
  mp_rev['R'] = 3;

  auto can_move = [&](int i, int j, int k) {
    char c = mat[i][j];
    return mat[i][j] == '?' || mp_rev[mat[i][j]] == k;
  };

  auto is_valid = [&](int i, int j) -> bool {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  map<char, int> mp_dir;
  mp_dir['D'] = 0;
  mp_dir['R'] = 1;
  mp_dir['U'] = 2;
  mp_dir['L'] = 3;

  vector<vector<bool>> in_cycle(n, vector<bool>(m));
  auto dfs = [&](auto& dfs, int i, int j) -> bool {
    vis[i][j] = 1;
    int k = mp_dir[mat[i][j]];
    int ii = i + dy[k], jj = j + dx[k];
    if (is_valid(ii, jj) && mat[ii][jj] != '?') {
      if (vis[ii][jj] == 0) {
        if (dfs(dfs, ii, jj)) {
          in_cycle[i][j] = true;
          return true;
        }
      }
      if (vis[ii][jj] == 1) {
        in_cycle[i][j] = true;
        in_cycle[ii][jj] = true;
        return true;
      }
      if (in_cycle[ii][jj]) {
        in_cycle[i][j] = true;
        return true;
      } 
    }
    vis[i][j] = 2;
    return false;
  };

  auto propagate = [&](auto& propagate, int i, int j) -> void {
    in_cycle[i][j] = true;
    for (int k = 0; k < 4; k++) {
      int ii = i + dy[k], jj = j + dx[k];
      if (is_valid(ii, jj) && can_move(ii, jj, k) && !in_cycle[ii][jj]) {
        propagate(propagate, ii, jj);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] != '?' && vis[i][j] == 0) {
        dfs(dfs, i, j);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == '?') {
        for (int k = 0; k < 4; k++) {
          int ii = i + dy[k], jj = j + dx[k];
          if (is_valid(ii, jj) && can_move(ii, jj, k)) {
            in_cycle[i][j] = true;
            break;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (in_cycle[i][j]) {
        propagate(propagate, i, j);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ans += in_cycle[i][j];
    }
  }

  cout << ans << '\n';
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