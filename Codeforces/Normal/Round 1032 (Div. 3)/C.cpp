#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, m;
  cin >> n >> m;
  int mx = 0;
  int mx_cnt = 0;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      mx = max(mx, a[i][j]);
    }
  }
  int mx2 = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == mx) {
        mx_cnt++;
      }
      else {
        mx2 = max(mx2, a[i][j]);
      }
    }
  }
  vector<int> row_mx(n), col_mx(m);
  vector<vector<bool>> with_mx(n, vector<bool>(m));
  vector<int> row_cnt(n), col_cnt(m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      row_mx[i] = max(row_mx[i], a[i][j]);
      col_mx[j] = max(col_mx[j], a[i][j]);
      if (a[i][j] == mx) {
        with_mx[i][j] = true;
        row_cnt[i]++;
        col_cnt[j]++;
      }
    }
  }
  int ans = mx;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int cnt = mx_cnt - row_cnt[i] - col_cnt[j] + (with_mx[i][j]);
      if (cnt == 0) {
        int nmx = max(row_mx[i], col_mx[j]) - 1;
        ans = min(ans, max(mx2, nmx));
      }
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