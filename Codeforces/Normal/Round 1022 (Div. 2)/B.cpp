#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

/*
  3 6

  0110
  [2, 4, 1]
  [3, 4, 1]

  2 27
  11011
  [1, 26]

  15 43
  101011
  [1, 2, 8, 32]
  [1, 2, 4, 8, 32]
  [1, 2, 4, 8, 32] + 1 * 10


  2 4
  [5, 1]

*/

void solve() {
  int n, x;
  cin >> n >> x;
  if (n == 1) {
    cout << (x == 0 ? -1 : x) << '\n';
    return;
  }
  int bits = __builtin_popcount(x);
  if (bits >= n) {
    cout << x << '\n';
    return;
  }
  if (!((n - bits) & 1)) {
    cout << x + n - bits << '\n';
    return;
  }
  if (x <= 1) {
    cout << n + 3 << '\n';  
    return;
  }
  cout << x + n - bits + 1 << '\n';
  // if (n == 2) {
  //   if (x == 0) {
  //     cout << 2 << '\n';
  //   }
  //   else if (x == 1) {
  //     cout << 5 << '\n';
  //   }
  //   else {
  //     cout << x + (bits == 1) * 2 << '\n';
  //   }
  //   return;
  // }
  // int ans = 0;
  // n -= bits - 1;
  // ans = x - (x & 1);
  // if (n & 1) {
  //   if (x & 1) {
  //     ans += x;
  //   }
  //   else {
  //     // 2 xor 3 = 1
  //     // necesito que n >= 3
  //     ans += 5 + (n - 4);
  //   }
  // }
  // else {
  //   if (x & 1) {
  //     // 0001111
  //     // ______
  //     ans += 5 + (n - 4);
  //   }
  //   else {
  //     ans += x;
  //   }
  // }
  // cout << ans << '\n';
  // /*
  //   3 6
  //   000110

  //   5
  //   001111
  //   17

  //   6
  //   001111
  //   17

  //   6
  //   000001
  // */
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