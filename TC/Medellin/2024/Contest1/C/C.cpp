#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) begin(x),end(x)
#define FOR(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define ROF(i, a, b) for(ll i = (ll)a - 1; i >= (ll)b; i--)
#define ENDL '\n'

void solve() {
  ll n, b, x;
  cin >> n >> b >> x;

  vi a(n);
  FOR (i, 0, n) {
    cin >> a[i];
  }

  auto sum = [](ll x) -> ll {
    return 1ll * x * (x + 1) / 2;
  };

  auto f = [&](ll k) -> ll {
    ll val = 0;
    FOR (i, 0, n) {
      if (a[i] <= k) {
        val += sum(a[i] - 1) * b;
        continue;
      }
      ll v1 = (a[i] + k - 1) / k;
      if (a[i] % k == 0) {
        val += (v1 * sum(k - 1) * v1) * b;
        continue;
      }
      ll v2 = v1 - 1;
      ll m1 = a[i] % k;
      ll m2 = k - m1;
      val += (v1 * sum(m1 - 1) * v1 + v2 * sum(m2 - 1) * v2 + v1 * v2 * m1 * m2) * b;
    }
    val -= (k - 1) * x;
    return val;
  };
  
  ll l = 1, r = 1e6;

  while (r - l > 10) {
    ll m1 = l + (r - l) / 3;
    ll m2 = r - (r - l) / 3;
    ll f1 = f(m1);
    ll f2 = f(m2);
    if (f1 < f2)
      l = m1;
    else
      r = m2;
  }

  ll mx = 0;
  FOR (i, l, r + 1) {
    mx = max(mx, f(i));
  }

  cout << mx << ENDL;
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