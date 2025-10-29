#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int mx = 0;
  for (int k = 1; k <= n; k++) {
    if (a[n - 1] < k + 1 || a[n - 2] < k + 1 || n - 2 < k) {
      break;
    }
    mx++;
  }

  cout << mx << '\n';
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