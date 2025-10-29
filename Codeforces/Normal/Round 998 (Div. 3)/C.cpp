#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n), c(n + 1);
  for (auto &x : a) {
    cin >> x;
    c[x]++;
  }
  int ans = 0;
  for (int x = 1; x <= n; x++) {
    int y = k - x;
    if (y <= 0 || y > n) continue;
    if (y == x) {
      int p = c[x] / 2;
      ans += p;
      c[x] -= p * 2;
      continue;
    }
    int p = min(c[x], c[y]);
    ans += p;
    c[x] -= p, c[y] -= p;
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