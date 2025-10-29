#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  map<ll, vector<int>> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ll falta = a[i] - (n - i);
    mp[falta].push_back(i);
  }

  vector<ll> dp(n, -1);
  auto f = [&](auto& f, int u, ll val) -> ll {
    ll nval = val + u;
    if (nval == val || mp[nval].empty()) {
      return nval;
    }
    ll& ans = dp[u];
    if (ans != -1) {
      return ans;
    }
    for (auto v : mp[nval]) {
      ans = max(ans, f(f, v, nval));
    }
    return ans;
  };

  ll mx = 0;

  for (auto u : mp[0]) {
    mx = max(mx, f(f, u, 0));
  }

  cout << mx + n << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    solve();
  }
  
  return 0;
}