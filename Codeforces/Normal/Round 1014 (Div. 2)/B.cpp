#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  int even = n / 2, odd = n - even;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1') {
      if (i & 1) {
        odd--;
      }
      else {
        even--;
      }
    }
    if (b[i] == '1') {
      if (i & 1) {
        even--;
      }
      else {
        odd--;
      }
    }
    if (even < 0 || odd < 0) {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
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