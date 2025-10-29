#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n, k;
  cin >> n >> k;
  vi a(k);
  ll mx = 0, imx = 0;
  FOR (i, 0, k) {
    cin >> a[i];
    if (a[i] > mx)
      mx = a[i], imx = i;
  }
  ll ans = 0, ones = 0;
  FOR (i, 0, k) {
    if (i == imx)
      continue;
    if (a[i] == 1) {
      ones++;
      continue;
    }
    // cout << a[i] << ' ' << a[i] - 1 << ENDL;
    ans += a[i] - 1;
    ones += a[i];
  }
  ans += ones;
  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  ll tc;
  cin >> tc;
  while (tc--) {
    // cout << "caso" << ENDL;
    solve();
  }
  return 0;
}