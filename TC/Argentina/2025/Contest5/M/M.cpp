#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define SZ(x) (int(x.size()))

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  int q;
  cin >> q;

  while (q--) {
    int x;
    cin >> x;
    int idx = int(upper_bound(a.begin(), a.end(), x) - a.begin());
    cout << idx << '\n';
  }

  return 0;
}