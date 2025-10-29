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

  sort(b.begin(), b.end());

  ll last = -1e18;
  for (ll i = 0; i < n; i++) {
    bool ok = 0;
    ll pos = 1e18;
    if (a[i] >= last) {
      ok = 1;
      pos = a[i];
    }
    /*
      Necesito el que me de la menor x mayor o igual a last

      x = b[j] - a[i];
      x >= last

      b[j] - a[i] >= last
      b[j] >= last + a[i];
    */
    auto it = lower_bound(b.begin(), b.end(), last + a[i]);
    if (it != b.end() && *it - a[i] >= last) {
      ok = 1;
      pos = min(pos, *it - a[i]);
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