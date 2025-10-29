#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  ll pos_sum = 0, neg_sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > 0) {
      pos_sum += a[i];
    }
    else {
      neg_sum -= a[i];
    }
  }
  ll ans = max(pos_sum, neg_sum);
  pos_sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      pos_sum += a[i];
    }
    else {
      neg_sum += a[i];
    }
    ans = max(ans, pos_sum + neg_sum);
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