#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) {
    cin >> x;
  }
  vector<int> b(n);
  for (auto &x : b) {
    cin >> x;
  }
  vector<vector<int>> val(3);
  for (int i = 0; i < n; i++) {
    val[a[i] + 1].push_back(i);
  }
  for (int i = n - 1; i >= 0; i--) {
    val[a[i] + 1].pop_back();
    if (b[i] > a[i] && val[2].empty()) {
      cout << "NO" << '\n';
      return;
    }
    if (b[i] < a[i] && val[0].empty()) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
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