#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

constexpr int blk = 317;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  for (auto &x : a) cin >> x;

  map<pair<int, int>, pair<vector<ll>, vector<ll>>> mp;

  while (q--) {
    int s, d, k;
    cin >> s >> d >> k;
    
    if (d >= blk) {
      ll ans = 0;
      for (int i = s - 1, j = 1; i < n, j <= k; i += d, j++) {
        ans += (ll)a[i] * j;
      }
      cout << ans << ' ';
      continue;
    }
    
    int sp = (s - 1) % d;

    if (!mp.count({sp, d})) {
      auto &[prefk, pref] = mp[{sp, d}];
      prefk = vector<ll>(n / d + 2);
      pref = vector<ll>(n / d + 2);
      for (int i = sp, j = 1; i < n; i += d, j++) {
        prefk[j] = prefk[j - 1] + (ll)a[i] * j;
        pref[j] = pref[j - 1] + a[i];
      }
    }

    auto &[prefk, pref] = mp[{sp, d}];
    int l = (s - 1) / d, r = l + k;
    ll ans = prefk[r] - prefk[l];
    ans -= (pref[r] - pref[l]) * l;
    cout << ans << ' ';
  }

  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}