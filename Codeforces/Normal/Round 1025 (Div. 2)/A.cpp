#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += (a[i] == 1);
  }
  if (cnt == n) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = 0; i < n - 1; i++) {
    if (a[i] == 0 && a[i + 1] == 0) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
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