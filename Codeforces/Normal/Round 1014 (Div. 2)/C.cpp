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
  ll cnt0 = 0, sum0 = 0, cnt1 = 0, sum1 = 0, mx0 = 0, mx1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      sum0 += a[i];
      cnt0++;
      mx0 = max(mx0, a[i]);
    }
    else {
      sum1 += a[i];
      cnt1++;
      mx1 = max(mx1, a[i]);
    }
  }
  if (cnt0 == n) {
    cout << mx0 << '\n';
    return;
  }
  if (cnt1 == n) {
    cout << mx1 << '\n';
    return;
  }
  if (cnt1 == 1) {
    cout << sum0 + sum1 << '\n';
    return;
  }
  cout << sum0 + sum1 - (cnt1 - 1) << '\n';
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