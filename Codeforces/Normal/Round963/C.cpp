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
  ll n, k;
  cin >> n >> k;

  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  
  sort(ALL(a));

  auto f = [&](ll m, ll x) -> ll {
    ll x_s = x + (k * m), x_e = x_s + k;
    ll y_s = a.back(), y_e = y_s + k;
    return x_s <= y_e && y_s <= x_e;
  };

  auto get = [&](ll x) -> int {
    ll l = 0, r = 1e9;
    while (l < r) {
      ll m = (l + r) / 2;
      if (x + (m * k) < a.back()) {
        l = m + 1;
      }
      else {
        r = m;
      }
    }

    ll res = -1, mx = 0;
    for (ll i = r - 1; i <= r + 1; i++) {
      ll val = f(i, x);
      if (!(i & 1) && val > mx) {
        mx = val;
        res = i;
      }
    }

    return res;
  };

  vector<ll> b;
  b.pb(a.back());
  FOR (i, 0, n - 1) {
    b.pb(a[i] + (get(a[i]) * k));
  }

  sort(ALL(b));

  if (b[0] + k - 1 < b.back()) {
    cout << -1 << ENDL;
    return;
  }

  cout << min(b[0] + k - 1, b.back()) << ENDL;
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