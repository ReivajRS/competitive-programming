#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<tuple<int, int, int>> a(n);
  for (auto &[x, y, h] : a) {
    cin >> x >> y >> h;
  }
  vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    int sq_mn = 1e9;
    auto [x0, y0, h0] = a[i];
    for (int j = 0; j < n; ++j) {
      auto [x1, y1, h1] = a[j];
      if (i != j && h1 > h0) {
        // (x0-x1)**2+(y0-y1)**2
        int dx = x0 - x1, dy = y0 - y1;
        sq_mn = min(sq_mn, dx * dx + dy * dy);
      }
    }
    int h = sqrt(sq_mn);
    while (h * h > sq_mn) {
      --h;
    }
    while (h * h <= sq_mn) {
      ++h;
    }
    --h;
    ans[i] = min(h, h0);
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }

  return 0;
}