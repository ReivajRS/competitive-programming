#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n, t;
  cin >> n >> t;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
  }

  auto f = [&](ll x) -> bool {
    ll products = 0;
    for (ll i = 0; i < n; i++) {
      products += x / a[i];
      if (products >= t) {
        return true;
      }
    }
    return products >= t;
  };

  ll l = 0, r = ll(1e18);

  while (l < r) {
    ll m = (l + r) / 2;
    if (f(m)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }

  cout << l << '\n';
}