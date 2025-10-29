#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  int idx = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == n) {
      idx = i;
    }
  }

  int l = max(0, idx - 1), r = min(n - 1, idx + 1);
  int now = n;
  while (now > 1) {
    now--;
    if (a[l] == now) {
      l = max(0, l - 1);
    }
    else if (a[r] == now) {
      r = min(n - 1, r + 1);
    }
    else {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  // cin >> tc;
  tc = 1;

  while (tc--) {
    solve();
  }

  return 0;
}