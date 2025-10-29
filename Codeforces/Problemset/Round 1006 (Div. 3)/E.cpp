#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int k;
  cin >> k;

  auto gauss = [](int x) -> ll {
    return ll(x) * (x + 1) / 2;
  };

  auto get_n = [&gauss](int k) -> int {
    int l = 0, r = k;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (gauss(m) > k) {
        r = m - 1;
      }
      else {
        l = m;
      }
    }
    return l;
  };

  int x = 0, y = 0;

  vector<pair<int, int>> pts;

  while (k > 0) {
    int n = get_n(k);
    for (int i = 0; i <= n; i++) {
      pts.push_back({x, y});
      x++;
    }
    y++;
    k -= gauss(n);
  }

  int sz = int(pts.size());
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    cout << pts[i].first << ' ' << pts[i].second << '\n';
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