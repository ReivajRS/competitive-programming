#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int& x: a) {
    cin >> x;
  }

  sort(a.begin(), a.end());

  ll P = ll(1e18) + 1, R = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (ll(a[i]) * (n - i) > R) {
      P = a[i];
      R = ll(a[i]) * (n - i);
    }
  }
  cout << P << ' ' << R << '\n';

  return 0;
}