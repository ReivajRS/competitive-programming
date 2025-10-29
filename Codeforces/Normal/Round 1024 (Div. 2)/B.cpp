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
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (abs(a[i]) < abs(a[0])) {
      cnt++;
    }
  }
  if (cnt > n / 2) {
    cout << "NO" << '\n';
  }
  else {
    cout << "YES" << '\n';
  }
}

/*
  2 3 8 10
  0 2 4 5
  0 9 10 13 23 24 223 456 999 1000
  10000 999 456 223 24 23 13 10 9 0
*/

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }

  return 0;
}