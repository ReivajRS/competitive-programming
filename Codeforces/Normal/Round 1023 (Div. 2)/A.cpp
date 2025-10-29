#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int g = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      g = gcd(g, a[j]);
    }
    if (a[i] != g) {
      cout << "Yes" << '\n';
      for (int j = 0; j < n; j++) {
        cout << (i == j ? 1 : 2) << ' ';
      }
      cout << '\n';
      return;
    }
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