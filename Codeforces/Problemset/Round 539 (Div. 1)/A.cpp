#include <bits/stdc++.h>
using namespace std;

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;
  
  vector<vector<int>> xpref(2, vector<int>(1 << 20 + 1));
  xpref[1][0] = 1;

  int xsum = 0;
  long long ans = 0;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    xsum ^= x;
    ans += xpref[i & 1][xsum];
    xpref[i & 1][xsum]++;
  }

  cout << ans << '\n';

  return 0;
}