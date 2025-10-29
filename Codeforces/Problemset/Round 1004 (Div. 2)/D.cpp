#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  int mn = 1e9, mx = -1;
  int idx1 = -1, idx2 = -1;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] < mn) {
      mn = a[i];
      idx1 = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] > mx && i != idx1) {
      mx = a[i];
      idx2 = i;
    }
  }
  idx1++, idx2++;
  int ans1, ans2;
  cout << "? " << idx1 << ' ' << idx2 << endl;
  cin >> ans1;
  cout << "? " << idx2 << ' ' << idx1 << endl;
  cin >> ans2;

  int dif = mx - mn;
  if (ans1 == 0 || ans2 == 0 || ans1 < dif || ans2 < dif) {
    cout << "! A" << endl;
  }
  else {
    cout << "! B" << endl;
  }
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