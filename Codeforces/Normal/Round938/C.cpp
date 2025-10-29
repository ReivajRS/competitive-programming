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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), ps(n + 1), psr(n + 1);
  ps[0] = 0;
  FOR (i, 0, n) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  vector<ll> b = a;
  reverse(ALL(b));
  psr[0] = 0;
  FOR (i, 0, n) {
    psr[i + 1] = psr[i] + b[i];
  }

  ll l = (k + 1) / 2, r = k / 2;

  ll leftAttack = 0;
  ll rightAttack = 0;

  FOR (i, 0, n + 1) {
    if (ps[i] <= l)
      leftAttack = i;
    if (psr[i] <= r)
      rightAttack = i;
  }

  ll lr = l - ps[leftAttack];
  ll rr = r - psr[rightAttack];
  ll ans = min(n, leftAttack + rightAttack);

  if (ans == n - 1) {
    FOR (i, 0, n + 1) {
      if (ps[i] <= l + rr)
        leftAttack = i;
    }
  }

  ans = min(n, leftAttack + rightAttack);

  if (ans == n - 1) {
    FOR (i, 0, n + 1) {
      if (psr[i] <= r + lr)
        rightAttack = i;
    }
  }

  ans = min(n, leftAttack + rightAttack);

  // cout << leftAttack << ' ' << rightAttack << ENDL;
  cout << ans << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}