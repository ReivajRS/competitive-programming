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
  vi a(n);
  for (auto &x : a)
    cin >> x;
  sort(ALL(a));
  ll ans = 0;
  vi b = {a[n-1], a[1], a[n-2], a[0]};
  FOR (i, 0, 4) {
    ans += abs(b[i] - b[(i + 1)%4]);
  }
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