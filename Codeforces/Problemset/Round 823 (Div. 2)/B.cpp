#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> x(n), t(n);
  
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> t[i];
  }

  auto f = [&](double m) -> double {
    double res = 0;
    for (int i = 0; i < n; i++) {
      res = max(res, abs(m - x[i]) + t[i]);
    }
    return res;
  };
  
  double l = 0, r = 1e8;

  for (int i = 0; i < 200; i++) {
    double m1 = l + (r - l) / 3;
    double m2 = r - (r - l) / 3;
    double f1 = f(m1);
    double f2 = f(m2);
    if (f1 > f2) {
      l = m1;
    }
    else {
      r = m2;
    }
  }

  cout << setprecision(8) << fixed;
  cout << l << '\n';
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