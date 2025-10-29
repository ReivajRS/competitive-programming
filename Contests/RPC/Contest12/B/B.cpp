#include <bits/stdc++.h>
using namespace std;
// Pura gente del Coach Moy
using ll = long long;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n, H;
  cin >> n >> H;

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    vector<int> l(3);
    cin >> l[0] >> l[1] >> l[2];
    sort(l.begin(), l.end());
    if (l[1] <= H || l[2] <= H) {
      ans += l[0];
    }
    else if (l[0] <= H || l[2] <= H) {
      ans += l[1];
    }
    else if (l[0] <= H || l[1] <= H) {
      ans += l[2];
    }
    else {
      cout << "impossible" << '\n';
      return 0;
    }
  }

  cout << ans << '\n';

  return 0;
}