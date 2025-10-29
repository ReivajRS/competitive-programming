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

const ll MOD = 1e9 + 7;

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(n);
  ll sum = 0;
  FOR (i, 0, n) {
    cin >> a[i];
    sum += a[i];
  }

  ll mx = 0, act = 0;
  FOR (i, 0, n) {
    act += a[i];
    if (mx < act)
      mx = act;
    if (act < 0)
      act = 0;
  }

  act = mx;
  FOR (i, 0, k) {
    sum = (sum % MOD + act % MOD + MOD) % MOD;
    act = (act * 2) % MOD;
  }

  sum = (sum + MOD) % MOD;

  cout << sum << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}