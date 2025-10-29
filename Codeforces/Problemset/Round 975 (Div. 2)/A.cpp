#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int even = n / 2, odd = n - even;
  int ans = 0;
  for (int i = 0; i < n; i += 2) {
    ans = max(ans, odd + a[i]);
  }
  for (int i = 1; i < n; i += 2) {
    ans = max(ans, even + a[i]);
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