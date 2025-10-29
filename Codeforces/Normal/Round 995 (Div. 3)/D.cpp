#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  ll n, x, y;
  cin >> n >> x >> y;
  vector<ll> a(n);
  ll total = 0;
  for (auto &x : a) {
    cin >> x;
    total += x;
  }

  /*
    x = 8, y = 10, suma_total = 19
    mn = 9, mx = 11
    3 4 6 6
    1, 3
    1, 4
    2, 3
    2, 4


    x = 8, y = 8, total = 11
    mn = 3, mx = 3
  */

  sort(a.begin(), a.end());
  ll ans = 0, mn = total - y, mx = total - x;
  for (int i = 0; i < n; i++) {
    ll lb = max(0ll, mn - a[i]);
    ll rb = min(a.back(), mx - a[i]);
    ll l = lower_bound(a.begin(), a.end(), lb) - a.begin();
    ll r = lower_bound(a.begin(), a.end(), rb + 1) - a.begin();
    // cout << a[i] << ' ' << l << ' ' << r << '\n';
    ll dif = r - l - (lb <= a[i] && a[i] <= rb);
    dif = max(0ll, dif);
    ans += dif;
  }
  cout << ans / 2 << '\n';
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