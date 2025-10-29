#include <bits/stdc++.h>
using namespace std;

using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int tc;
  cin >> tc;

  while (tc--) {
    ll x, y;
    cin >> y >> x;
    if (x >= y) {
      if (x & 1) {
        ll square = x * x;
        cout << square - y + 1 << '\n';
      }
      else {
        ll square = (x - 1) * (x - 1);
        cout << square + y << '\n';
      }
    }
    else {
      if (y & 1) {
        ll square = (y - 1) * (y - 1);
        cout << square + x << '\n';
      }
      else {
        ll square = y * y;
        cout << square - x + 1 << '\n';
      }
    }
  }
  
  return 0;
}