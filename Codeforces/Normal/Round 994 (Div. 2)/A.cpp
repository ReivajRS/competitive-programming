#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &x : a) cin >> x;
  int zeros = count(a.begin(),a.end(), 0);
  if (zeros == n) {
    cout << 0 << '\n';
    return;
  }
  int fnz = 0, lnz = n - 1;
  for (; fnz < n; fnz++) {
    if (a[fnz] != 0) break;
  }
  for (; lnz >= 0; lnz--) {
    if (a[lnz] != 0) break;
  }
  cout << fnz << ' ' << lnz << '\n';
  for (; fnz <= lnz; fnz++) {
    if (a[fnz] == 0) {
      cout << 2 << '\n';
      return;
    }
  }
  cout << 1 << '\n';
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