#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  for (auto& x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());

  int l = 0, r = m - 1, cnt = 0;
  while (l < r && cnt + 2 <= n) {
    for (int i = 0; i < 3; i++) {
      cout << a[l] << ' ' << a[r] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < 3; i++) {
      cout << a[r] << ' ' << a[l] << ' ';
    }
    cout << '\n';
    l++, r--;
    cnt += 2;
  }
  if (cnt == n - 1) {
    for (int i = 0; i < 3; i++) {
      cout << a[l] << ' ' << a[r] << ' ';
    }
    cout << '\n';
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