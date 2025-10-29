#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  
  vector<int> row_max(n);

  auto compute_row = [&](int row) {
    row_max[row] = 0;
    for (int j = 0; j < m; j++) {
      if (j > 0 && a[row][j] > 0) {
        a[row][j] = a[row][j - 1] + 1;
      }
      row_max[row] = max(row_max[row], a[row][j]);
    }
  };

  for (int i = 0; i < n; i++) {
    compute_row(i);
  }

  while (q--) {
    int r, c;
    cin >> r >> c;
    r--, c--;
    a[r][c] = a[r][c] > 0 ? 0 : 1;
    compute_row(r);
    cout << *max_element(row_max.begin(), row_max.end()) << '\n';
  }
  
  return 0;
}