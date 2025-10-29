#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> a(n, vector<int>(m));
  vector<int> row_in_a(n * m + 1), row_in_b(n * m + 1);
  vector<int> col_in_a(n * m + 1), col_in_b(n * m + 1);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      row_in_a[a[i][j]] = i;
      col_in_a[a[i][j]] = j;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      row_in_b[x] = i;
      col_in_b[x] = j;
    }
  }

  for (int i = 0; i < n; i++) {
    int row_b = row_in_b[a[i][0]];
    for (int j = 1; j < m; j++) {
      if (row_in_b[a[i][j]] != row_b) {
        cout << "NO" << '\n';
        return;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    int col_b = col_in_b[a[0][j]];
    for (int i = 1; i < n; i++) {
      if (col_in_b[a[i][j]] != col_b) {
        cout << "NO" << '\n';
        return;
      }
    }
  }

  cout << "YES" << '\n';
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