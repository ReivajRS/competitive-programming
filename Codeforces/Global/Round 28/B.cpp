#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  // 4 1 3 2
  /*
    4 1 -> 1
    1 3 -> 1
    3 2 -> 2


    8 7 1 6 5 2 4 3
    8 7 1 -> 1
    7 1 6 -> 1
    1 6 5 -> 1
    6 5 2 -> 2
    5 2 4 -> 2
    2 4 5 -> 2
  */

  int n, k;
  cin >> n >> k;
  int l = 1, r = n;
  for (int i = 1; i <= n; i++) {
    if (i % k == 0) {
      cout << l << ' ';
      l++;
      continue;
    }
    cout << r << ' ';
    r--;
  }
  cout << '\n';
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