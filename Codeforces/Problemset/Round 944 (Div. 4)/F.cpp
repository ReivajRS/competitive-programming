#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll r;
  cin >> r;

  ll cr1 = r * r, cr2 = (r + 1) * (r + 1);

  ll ans = 0;

  for (ll y = r; y > 0; y--) {
    ll y2 = y * y;
    ll lo = ll(ceil(sqrt(cr1 - y2)));
    ll hi = ll(floor(sqrt(cr2 - y2)));

    if (hi * hi + y2 == cr2) {
      hi--;
    }

    ans += hi - lo + 1;
  }

  cout << ans * 4 << '\n';
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