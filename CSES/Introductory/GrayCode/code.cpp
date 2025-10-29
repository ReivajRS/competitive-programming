#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int n;
  cin >> n;
  
  for (int i = 0; i < (1 << n); i++) {
    int gray = i ^ (i >> 1);
    for (int j = n - 1; j >= 0; j--) {
      cout << (gray >> j & 1);
    }
    cout << '\n';
  }
  
  return 0;
}