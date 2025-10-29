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


  /*
    4 4
    4 3 7 5
    2 5 4 6
    
    4 2 3 1
    0 1 0 1

    Los que no puedes resolver, metelos juntos. Es mejor asi
    Cuando x = m % k, los x problemas que no puedo resolver y
    resuelven mas personas, se descartan de los grupos

    2 1 4 3
    1 1 0 0
  */

  ll kr = a[0];
  sort(a.begin(), a.end());
  vector<pair<ll, ll>> info;
  for (ll i = 0; i < m; i++) {
    ll cnt = n - (lower_bound(a.begin(), a.end(), b[i]) - a.begin());
    info.push_back({kr < b[i], cnt});
  }

  sort(info.rbegin(), info.rend());

  for (ll k = 1; k <= m; k++) {
    ll rem = m % k;
    ll ans = m / k;
    for (ll i = rem; i < m; i += k) {
      ans += info[i].second * info[i].first;
    }
    cout << ans << ' ';
  }
  cout << '\n';
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