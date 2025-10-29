#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
#define SZ(x) ((int)(x).size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ans = n - 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if ((a[i] + a[j]) % 2 == 0) {
        int rem = i + (n - j - 1);
        ans = min(ans, rem);
      }
    }
  }
  cout << ans << '\n';
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