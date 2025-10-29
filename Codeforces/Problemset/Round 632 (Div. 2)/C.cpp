#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  ll n;
  cin >> n;
  vector<int> a(n);
  vector<ll> pref(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pref[i + 1] = pref[i] + a[i];
  }
  ll ans = n * (n + 1) / 2;
  map<ll, int> mp;
  int bad = 1e6;
  for (int i = n; i >= 1; i--) {
    if (a[i - 1] == 0) {
      bad = i;
    }
    int mn_bad = bad;
    if (mp.count(pref[i - 1])) {
      bad = min(bad, mp[pref[i - 1]]);
    }
    mp[pref[i]] = i;
    if (bad == 1e6) {
      continue;
    }
    ans -= n - bad + 1;
  }

  cout << ans << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  // cin >> tc;
  tc = 1;

  while (tc--) {
    solve();
  }

  return 0;
}