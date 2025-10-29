#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<ll> s(n);
  for (int i = 0; i < n; i++) {
    ll pref = 0;
    for (int j = 0; j < m; j++){ 
      cin >> a[i][j];
      pref += a[i][j];
    }
    s[i] = pref;
  }
  vector<int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int i, int j) -> bool {
    return s[i] > s[j];
  });
  ll pref = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      pref += a[p[i]][j];
      ans += pref;
    }
  }
  cout << ans << '\n';
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