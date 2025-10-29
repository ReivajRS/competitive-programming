#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;

  string s;
  cin >> s;

  vector<vector<ll>> mat(n, vector<ll>(m));
  vector<ll> row_sum(n), col_sum(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
      row_sum[i] += mat[i][j];
      col_sum[j] += mat[i][j];
    }
  }
  
  vector<int> row_cnt(n), col_cnt(m);
  row_cnt[0] = col_cnt[0] = 1;
  int ii = 0, jj = 0;
  vector<pair<int, int>> path = {{0, 0}};
  for (int i = 0; i < n + m - 2; i++) {
    if (s[i] == 'D') {
      ii++;
    }
    else {
      jj++;
    }
    row_cnt[ii]++;
    col_cnt[jj]++;
    path.push_back({ii, jj});
  }

  for (auto [i, j] : path) {
    if (row_cnt[i] == 1) {
      mat[i][j] = -row_sum[i];
      col_sum[j] += mat[i][j];
      row_sum[i] = 0;
    }
    else {
      mat[i][j] = -col_sum[j];
      row_sum[i] += mat[i][j];
      col_sum[j] = 0;
    }
    row_cnt[i]--;
    col_cnt[j]--;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
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