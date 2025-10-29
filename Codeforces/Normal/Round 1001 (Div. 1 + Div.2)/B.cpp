#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  bool ok = true;
  for (int i = 0; i < n; i++) {
    ll x;
    cin >> x;
    ll l = i;
    ll r = n - i - 1;
    if (x <= 2 * l || x <= 2 * r) {
      ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << '\n';
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