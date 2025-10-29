#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {

  /*
    5 1 2 3 4
    _ 1 2 3 4
  */

  int n;
  cin >> n;
  if (n & 1) {
    cout << n;
    for (int i = 1; i < n; i++) {
      cout << ' ' << i;
    }
    cout << '\n';
  }
  else {
    cout << -1 << '\n';
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