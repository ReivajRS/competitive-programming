#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    bool flag = 1;
    for (int j = 0; j < n; j++) {
      if (i != j && abs(a[i] - a[j]) % k == 0) {
        flag = 0;
        break;
      }
    }
    if (flag) {
      cout << "YES" << '\n';
      cout << i + 1 << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
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