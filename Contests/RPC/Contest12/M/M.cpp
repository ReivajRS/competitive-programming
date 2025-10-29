#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using i64 = long long;
signed main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  auto f = [&](int a0) -> i64 {
    i64 ret = 0;
    for (int i = 0; i < n; ++i) {
      ret += abs(a0 + i - a[i]);
    }
    return ret;
  };
  int l = -2e7, r = 2e7;
  while (r - l > 5) {
    int m1 = l + (r - l) / 3;
    int m2 = r - (r - l) / 3;
    if (f(m1) < f(m2)) {
      r = m2;
    } else {
      l = m1;
    }
  }
  i64 ans = 1e18;
  while (l <= r) {
    ans = min(ans, f(l));
    ++l;
  }
  cout << ans << '\n';
  return 0;
}