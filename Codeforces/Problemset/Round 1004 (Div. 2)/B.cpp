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
  vector<bool> in_bag(n + 5, 0);
  for (int i = 0; i < n; i++) {
    while (in_bag[a[i]]) {
      a[i]++;
    }
    if (i > 0 && a[i - 1] == a[i]) {
      in_bag[a[i]] = 1;
    }
  }
  for (auto &x : a) {
    if (!in_bag[x]) {
      cout << "No" << '\n';
      return;
    }
  }
  cout << "Yes" << '\n';
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