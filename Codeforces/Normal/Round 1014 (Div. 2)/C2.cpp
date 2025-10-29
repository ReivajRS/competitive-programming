#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  sort(a.rbegin(), a.rend());
  ll mx_odd = 0, mx_idx = -1;
  ll cnt0 = 0, sum0 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      sum0 += a[i];
      cnt0++;
    }
    else {
      if (a[i] > mx_odd) {
        mx_odd = a[i];
        mx_idx = i;
      }
    }
  }
  if (mx_idx == -1) {
    cout << a[0] << '\n';
    return;
  }
  ll sum = mx_odd + sum0;
  ll ans = sum;
  for (int i = 0; i < n; i++) {
    if (i != mx_idx && a[i] % 2 == 1 && cnt0 > 0 && sum0 > 0) {
      cnt0--, sum0--;
      sum += a[i] - 1;
      ans = max(ans, sum);
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