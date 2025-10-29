#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  ll n;
  cin >> n;
  /*
    [4, 3, 2, 1] = (4 - 1) + (3 - 2) + (2 - 3) + (1 - 4) = 3 + 2 + 2 + 3 = 8
    [5, 4, 3, 2, 1] = 4 + 2 + 0 + 2 + 4 = 12
    [6, 5, 4, 3, 2, 1] = 5 + 3 + 1 + 1 + 3 + 5 = 18
    [8, 7, 6, 5, 4, 3, 2, 1] = 7 + 5 + 3 + 1 + 1 + 3 + 5 + 7 = 32
  */
  ll sum = 0;
  for (ll i = 1; i <= n; i++) {
    sum += abs(i - (n - i + 1));
  }
  cout << sum / 2 + 1 << '\n';
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