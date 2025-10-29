#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  for (ll i = 1; i <= n; i++) {
    ll ans = i * i * (i * i - 1) / 2;
    ans -= 4 * (i - 1) * (i - 2);
    cout << ans << '\n';
  }
  
  return 0;
}