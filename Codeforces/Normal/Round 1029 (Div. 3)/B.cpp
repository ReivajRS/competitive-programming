#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  /*
    1 3 5 6 4 2 - 6
    1 3 5 4 2 - 5
    1 3 4 2 - 4
    1 3 2 - 3

    3 5 6 4 2 1
    3 5 4 2 1
    3 4 2 1
    3 2 1
    
  */

  int n;
  cin >> n;
  vector<int> a(n);
  int lp, rp;
  if (n & 1) {
    lp = rp = n / 2;
  }
  else {
    lp = rp = (n + 1) / 2;
  }
  int x = n;
  while (x > 0) {
    if (lp == rp) {
      a[lp] = x--;
      lp--, rp++;
    }
    if (lp >= 0) {
      a[lp--] = x--;
    }
    if (rp < n) {
      a[rp++] = x--;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
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