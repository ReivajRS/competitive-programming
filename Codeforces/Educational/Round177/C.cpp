#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(ll u, ll ndfs, vector<ll>& p, vector<ll>& vis) {
  vis[u] = ndfs;
  if (vis[p[u]] == -1) {
    dfs(p[u], ndfs, p, vis);
  }
}

void solve() {
  ll n;
  cin >> n;
  vector<ll> p(n);
  for (auto &x : p) {
    cin >> x;
    x--;
  }
  vector<ll> d(n);
  for (auto &x : d) {
    cin >> x;
    x--;
  }
  vector<ll> vis(n + 1, -1);
  ll ndfs = 0;
  for (ll i = 0; i < n; i++) {
    if (vis[i] == -1) {
      dfs(i, ndfs++, p, vis);
    }
  }
  vector<ll> sz(n + 1);
  for (ll i = 0; i < n; i++) {
    sz[vis[i]]++;
  }
  ll ans = 0;
  for (auto x : d) {
    ans += sz[vis[x]];
    sz[vis[x]] = 0;
    cout << ans << ' ';
  }
  cout << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll tc;
  cin >> tc;

  while (tc--) {
    solve();
  }

  return 0;
}