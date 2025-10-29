#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll mn = 1e18 + 5, idx = -1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < mn) {
      mn = a[i];
      idx = i;
    }
  }
  ll g = 0;
  for (int i = 0; i < n; i++) {
    if (i != idx && a[i] % mn == 0) {
      g = gcd(g, a[i]);
    }
  }
  if (mn == g) {
    cout << "Yes" << '\n';
  }
  else {
    cout << "No" << '\n';
  }
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