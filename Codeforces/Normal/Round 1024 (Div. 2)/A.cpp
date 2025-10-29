#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, m, p, q;
  cin >> n >> m >> p >> q;
  if (n % p == 0 && m != (n / p) * q) {
    cout << "NO" << '\n';
  }
  else {
    cout << "YES" << '\n';
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