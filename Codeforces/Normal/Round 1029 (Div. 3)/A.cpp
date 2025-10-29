#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool flag = 0;
  for (int i = 0; i < n; i++) {
    int d = a[i];
    if (!flag) {
      if (d == 1) {
        if (x >= 1) {
          flag = 1;
        }
        else {
          cout << "NO" << '\n';
          return;
        }
      }
    }
    if (flag) {
      x--;
      if (x == 0) {
        flag = 0;
      }
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