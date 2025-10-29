#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

bool check(ll x) {
  if (x < 2) {
    return false;
  }
  for (ll p = 2; p * p <= x; p++) {
    if (x % p == 0) {
      return false;
    }
  }
  return true;
}

void solve() {
  ll x, k;
  cin >> x >> k;
  if (k == 1 && check(x)) {
    cout << "YES" << '\n';
    return;
  }
  if (k == 2 && x == 1) {
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