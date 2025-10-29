#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  int px = 0, py = 0;
  for (auto &[x, y] : a) {
    cin >> x >> y;
    x = px + x, y = py + y;
    px = x, py = y;
  }
  int p = m * 4;
  for (int i = 1; i < n; i++) {
    auto [x1, y1] = a[i - 1];
    auto [x2, y2] = a[i];
    x1 += m, y1 += m;
    int inter = (x1 - x2) + (y1 - y2);
    p += m * 4 - inter * 2;
  }
  cout << p << '\n';
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