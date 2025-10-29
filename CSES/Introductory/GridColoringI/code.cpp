#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  vector<string> grid(n);
  for (int i = 0; i < n; i++) {
    cin >> grid[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vector<int> used(4);
      if (i > 0) {
        used[grid[i - 1][j] - 'A'] = true;
      }
      if (j > 0) {
        used[grid[i][j - 1] - 'A'] = true;
      }
      used[grid[i][j] - 'A'] = true;
      for (int k = 0; k < 4; k++) {
        if (!used[k]) {
          grid[i][j] = char(k + 'A');
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << grid[i] << '\n';
  }
}