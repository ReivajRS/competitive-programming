#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, q;
  cin >> n >> q;
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  map<ll, ll> mp;
  for (int i = 0; i < n; i++) {
    ll now = ll(i) * (n - i) + (n - i -
       1);
    mp[now]++;
    if (i < n - 1) {
      now = ll(i) * (n - i - 1) + (n - i - 1);
      mp[now] += x[i + 1] - x[i] - 1;
    }
  }
  for (int i = 0; i < q; i++) {
    ll x;
    cin >> x;
    cout << mp[x] << ' ';
  }
  cout << '\n';
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