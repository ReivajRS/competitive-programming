#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < k ; i++) {
    cout << '1';
  }
  for (int i = 0; i < n - k; i++) {
    cout << '0';
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