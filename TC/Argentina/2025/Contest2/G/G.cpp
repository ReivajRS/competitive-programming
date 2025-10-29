#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll ans = 0;
  ll last = 1e9 + 1;
  for (int i = n - 1; i >= 0; i--) {
    ll x = max(0ll, min(last - 1, a[i]));
    last = x;
    ans += x;
  }

  cout << ans << '\n';

  return 0;
}