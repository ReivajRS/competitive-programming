#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  ll n, k, x;
  cin >> n >> k >> x;
  vector<ll> a(n);
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }
  ll total = pref[n] * k;
  ll l = 0, r = n * k;
  l = 0, r = n * k;
  while (l < r) {
    ll m = (l + r) / 2;
    ll sum = m / n * pref[n];
    sum += pref[m % n];
    if (sum < total - x + 1) {
      l = m + 1;
    }
    else {
      r = m;
    }
  }
  cout << l << '\n';
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