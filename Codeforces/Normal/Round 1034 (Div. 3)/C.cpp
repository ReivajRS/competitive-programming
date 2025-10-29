#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> pref_mn(n, 1e9), suff_mx(n, -1);
  pref_mn[0] = a[0];
  for (int i = 1; i < n; i++) {
    pref_mn[i] = min(pref_mn[i - 1], a[i]);
  }
  suff_mx[n - 1] = a[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suff_mx[i] = max(suff_mx[i + 1], a[i]);
  }
  for (int i = 0; i < n; i++) {
    if (pref_mn[i] == a[i] || suff_mx[i] == a[i]) {
      cout << '1';
    }
    else {
      cout << '0';
    }
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