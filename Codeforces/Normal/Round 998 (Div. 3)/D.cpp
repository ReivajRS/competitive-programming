#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

/*
  uno se vuelve 0 y el otro x - min

  4 5 2 3
  0 1 2 3
  0 0 1 3
  0 0 0 2

  4 5 4 5 4 5 4 5
  0 1 4 5 4 5 4 5
  0 0 3 5 4 5 4 5
  0 0 0 2 4 5 4 5
  0 0 0 0 2 5 4 5
  0 0 0 0 0 3 4 5
  0 0 0 0 0 0 1 5
*/

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  if (is_sorted(a.begin(), a.end())) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] > a[i + 1]) {
      cout << "NO" << '\n';
      return;
    }
    int mn = min(a[i], a[i + 1]);
    a[i] -= mn, a[i + 1] -= mn;
  }
  // for (auto &x : a) cout << x << ' ';
  // cout << '\n';
  if (is_sorted(a.begin(), a.end())) {
    cout << "YES" << '\n';
    return;
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