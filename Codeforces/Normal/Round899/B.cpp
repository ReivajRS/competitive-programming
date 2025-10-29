#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  ll n;
  cin >> n;
  
  vector<ll> s(n, 0);
  FOR (i, 0, n) {
    ll k;
    cin >> k;
    while (k--) {
      ll x;
      cin >> x;
      s[i] |= (1ll << x);
    }
  }

  ll u = 0;
  for (auto &x : s)
    u |= x;
  
  int mx = 0;
  FOR (i, 1, 51) {
    if (!(u & (1ll << i)))
      continue;
    ll v = 0;
    for (auto &x : s) {
      if (!(x & (1ll << i)))
        v |= x;
    }
    mx = max(mx, __builtin_popcountll(v));
  }

  cout << mx << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}