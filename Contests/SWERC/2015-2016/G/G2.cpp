#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int p, k;
  cin >> p >> k;

  int nsum = 0;
  
  while (p--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), g(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      int has = 0;
      for (int j = i; j >= max(1, i - k); j--) {
        if (j - a[j] < 0) {
          continue;
        }
        has |= (1 << g[j - a[j]]);
      }
      for (int x = 0; x <= 11; x++) {
        if (!((has >> x) & 1)) {
          g[i] = x;
          break;
        }
      }
    }
    nsum ^= g[n];
  }

  cout << (nsum ? "Alice can win." : "Bob will win.") << '\n';

  return 0;
}