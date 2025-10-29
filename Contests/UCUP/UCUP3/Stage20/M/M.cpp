#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;
  
    vector<vector<int>> ans(n, vector<int>(m));
    for (int c = 0, curr = 1; c < n + m; ++c) {
      for (int d = 0; d < n + m; ++d) {
        int i = d, j = c - d;
        if (i >= 0 && i < n && j >= 0 && j < m) {
          ans[i][j] = curr++;
        }
      }
    }
  
    cout << "YES\n";
    for (auto& row : ans) {
      for (int& x : row) {
        cout << x << ' ';
      }
      cout << '\n';
    }
  }
}