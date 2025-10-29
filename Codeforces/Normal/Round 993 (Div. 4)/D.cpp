#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<bool> used(n + 1, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> b(n);
  vector<int> any;

  for (int i = 0; i < n; i++) {
    if (!used[a[i]]) {
      b[i] = a[i];
      used[a[i]] = 1;
      continue;
    }
    any.push_back(i);
  }

  int mx = 1;

  while (!any.empty()) {
    int i = any.back();
    any.pop_back();
    for (; mx <= n; mx++) {
      if (!used[mx]) {
        b[i] = mx;
        used[mx] = 1;
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << b[i] << " \n"[i == n - 1];
  }
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