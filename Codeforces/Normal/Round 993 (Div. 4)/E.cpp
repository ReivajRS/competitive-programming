#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  ll k, l1, r1, l2, r2;
  cin >> k >> l1 >> r1 >> l2 >> r2;

  ll ans = 0;

  for (ll p = 1; p <= r2; p *= k) {
    ll l = (l2 + p - 1) / p;
    l = max(l, l1);
    ll r = r2 / p;
    r = min(r, r1);
    ans += max(0ll, r - l + 1);
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