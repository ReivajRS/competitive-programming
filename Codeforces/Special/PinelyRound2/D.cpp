#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, m;
  cin >> n >> m;

  vector<string> mat(n);
  vector<int> cnt_row(n);
  vector<int> cnt_col(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == 'L' || mat[i][j] == 'R') {
        cnt_col[j]++;
      }
      if (mat[i][j] == 'U' || mat[i][j] == 'D') {
        cnt_row[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < m; j++) {
      cnt += (mat[i][j] != '.');
    }
    if (cnt & 1) {
      cout << -1 << '\n';
      return;
    }
  }
  for (int j = 0; j < m; j++) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
      cnt += (mat[i][j] != '.');
    }
    if (cnt & 1) {
      cout << -1 << '\n';
      return;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      
    }
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