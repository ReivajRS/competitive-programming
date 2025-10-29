#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, q;
  cin >> n >> q;
  
  int LOG = ceil(log2(1e9));
  vector<vector<int>> g(n, vector<int>(LOG));
  for (int i = 0; i < n; i++) {
    cin >> g[i][0];
    g[i][0]--;
  }

  for (int k = 1; k < LOG; k++) {
    for (int i = 0; i < n; i++) {
      g[i][k] = g[g[i][k - 1]][k - 1];
    }
  }

  while (q--) {
    int x, k;
    cin >> x >> k;
    x--;
    for (int i = 0; i < LOG; i++) {
      if (1 & (k >> i)) {
        x = g[x][i];
      }
    }
    cout << x + 1 << '\n';
  }
  
  return 0;
}