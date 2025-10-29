#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int x, y;
  cin >> x >> y;
  int d = x - y + 1;
  if (d % 9 == 0 && d >= 0) {
    cout << "Yes" << '\n';
    return;
  }
  cout << "No" << '\n';
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