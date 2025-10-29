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

ll log3(ll x) {
  ll cnt = 0;
  while (x) {
    x /= 3;
    cnt++;
  }
  return cnt;
}

vector<ll> logs;
vector<ll> pref;

void precalc(ll n) {
  logs.assign(n + 5, 0);
  pref.assign(n + 5, 0);
  for (ll i = 1; i <= n; i++) {
    logs[i] = log3(i);
    pref[i] = pref[i - 1] + logs[i];
  }
}

void solve() {
  ll l, r;
  cin >> l >> r;
  ll ans = pref[r] - pref[l - 1];
  ans += logs[l];
  cout << log2(100000) / log2(3) << ENDL;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  precalc(300000);
  
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}