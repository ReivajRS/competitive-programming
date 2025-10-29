#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == k) {
    int ans = 1;
    for (int i = 1; i < n; i += 2) {
      if (a[i] == ans) {
        ans++;
      }
      else {
        break;
      }
    }
    cout << ans << '\n';
    return;
  }
  int ans1 = 1e9 + 5;
  for (int i = 0; i < n - 1; i++) {
    if (n - i < k) {
      break;
    }
    if (a[i + 1] != 1) {
      ans1 = min(ans1, 1);
    }
  }
  a.erase(a.begin());
  n--, k--;
  int ans2 = 1e9 + 5;
  for (int i = 0; i < n - 1; i++) {
    if (n - i < k) {
      break;
    }
    if (a[i + 1] != a[i] + 1) {
      ans2 = min(ans2, a[i] + 1);
    }
  }
  cout << min(ans1, ans2) << '\n';
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