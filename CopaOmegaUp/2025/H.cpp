#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll n;
  cin >> n;

  vector<ll> a(n);
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> pref(n + 1);
  for (ll i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + a[i];
  }

  ll q;
  cin >> q;

  while (q--) {
    ll l, r;
    cin >> l >> r;
    
    ll ans = 0;
    map<ll, ll> mp;
    for (ll i = l - 1; i <= r; i++) {
      ans += mp[pref[i]];
      mp[pref[i]]++;
    }

    cout << ans << '\n';
  }
  
  return 0;
}