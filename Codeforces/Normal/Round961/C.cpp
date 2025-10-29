#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

void solve() {
  ll n, m;
  cin >> n >> m;

  vector<pair<ll, ll>> a;
  map<ll, ll> mp;
  FOR (i, 0, n) {
    ll x;
    cin >> x;
    mp[x]++;
  }
  for (auto &[k, v] : mp) {
    a.pb({k, v});
  }

  auto get = [&m](pair<ll, ll> x, pair<ll, ll> y) -> ll {
    auto [n1, c1] = x;
    auto [n2, c2] = y;
    if (n1 * c1 + n2 * c2 <= m)
      return n1 * c1 + n2 * c2;
    ll dif = m;
    ll v1 = min(dif / n1, c1);
    dif -= v1 * n1;
    ll v2 = min(dif / n2, c2);
    dif -= v2 * n2;
    ll sw = min({dif, c2 - v2, v1});
    return m - (dif - sw);
  };

  ll mx = 0;

  FOR (i, 0, n) {
    mx = max(mx, min(m / a[i].first, a[i].second) * a[i].first);
    if (i + 1 < n && a[i + 1].first - a[i].first <= 1)
      mx = max(mx, get(a[i], a[i + 1]));
  }

  cout << mx << ENDL;
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