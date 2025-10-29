#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<tuple<ll, ll, ll>> a(n);
  for (ll i = 0; i < n; i++) {
    ll l, r, real;
    cin >> l >> r >> real;
    a[i] = {l, r, real};
  }
  sort(a.begin(), a.end());
  for (auto [l, r, real] : a) {
    if (l <= k && k <= r && real > k) {
      k = real;
    }
  }
  cout << k << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}