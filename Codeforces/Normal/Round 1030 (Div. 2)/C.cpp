#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((ll)(x).size())

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (ll j = 0; j < 62; j++) {
    for (ll i = 0; i < n; i++) {
      ll x = (1ll << j);
      if (a[i] & x) {
        continue;
      }
      if (k >= x) {
        a[i] |= x;
        k -= x;
      }
    }
  }

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ans += __builtin_popcountll(a[i]);
  }

  cout << ans << '\n';
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