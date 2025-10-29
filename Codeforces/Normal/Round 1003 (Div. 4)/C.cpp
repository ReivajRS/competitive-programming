#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((ll)x.size())
using ll = long long;

void solve() {
  ll n, m;
  cin >> n >> m;
  
  vector<ll> a(n), b(m);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  ll last = -1e18;
  for (ll i = 0; i < n; i++) {
    ll x = b[0] - a[i];
    bool ok = 0;
    ll pos = 1e18;
    if (a[i] >= last) {
      ok = 1;
      pos = a[i];
    }
    if (x >= last) {
      ok = 1;
      pos = min(pos, x);
    }
    if (!ok) {
      cout << "NO" << '\n';
      return;
    }
    last = pos;
  }

  cout << "YES" << '\n';
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