#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)(x).size())

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= m) {
      cout << i + 1 << '\n';
      return 0;
    }
  }
  
  cout << -1 << '\n';
  
  return 0;
}