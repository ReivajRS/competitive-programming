#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, k;
  cin >> n >> k;
  ll sum = 0;
  int mn = 1e9 + 5, mx = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
    sum += a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (a[i] == mx);
  }
  if (mx - mn > k + 1 || (cnt > 1 && mx - mn == k + 1)) {
    cout << "Jerry" << '\n';
    return;
  }
  cout << (sum & 1 ? "Tom" : "Jerry") << '\n';
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