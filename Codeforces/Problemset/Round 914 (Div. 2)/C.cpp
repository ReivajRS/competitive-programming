#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (auto& x : a) {
    cin >> x;
  }
  if (k >= 3) {
    cout << 0 << '\n';
    return;
  }
  sort(a.begin(), a.end());
  ll ans = *min_element(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    ans = min(ans, a[i] - a[i - 1]);
  }
  if (k == 1) {
    cout << ans << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll x = a[j] - a[i];
      int k = int(lower_bound(a.begin(), a.end(), x) - a.begin());
      if (k - 1 >= 0) {
        ans = min(ans, abs(x - a[k - 1]));
      }
      if (k < n) {
        ans = min(ans, abs(x - a[k]));
      }
      if (k + 1 < n) {
        ans = min(ans, abs(x - a[k + 1]));
      }
    }
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