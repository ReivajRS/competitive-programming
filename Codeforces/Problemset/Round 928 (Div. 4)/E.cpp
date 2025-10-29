#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, k;
  cin >> n >> k;
  k--;

  int p = 1;
  while (k) {
    int x = (n + 2 - 1) / 2;
    if (k - x < 0) {
      break;
    }
    k -= x;
    n -= x;
    p *= 2;
  }

  cout << p * (k * 2 + 1) << '\n';
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