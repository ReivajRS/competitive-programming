#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) (int(x.size()))

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll r, x1, y1, x2, y2;
  cin >> r >> x1 >> y1 >> x2 >> y2;

  double dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  double move = 2 * r;
  ll ans = ll(ceil(dist / move));

  cout << ans << '\n';

  return 0;
}