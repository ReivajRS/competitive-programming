#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int m, a, b, c;
  cin >> m >> a >> b >> c;
  int r1 = m;
  int r2 = m;
  int ans = 0;
  int mn = min(r1, a);
  ans += mn;
  r1 -= mn;
  mn = min(r2, b);
  ans += mn;
  r2 -= mn;
  ans += min(r1 + r2, c);
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