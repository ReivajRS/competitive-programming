#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  vector<int> a(5);
  cin >> a[0] >> a[1] >> a[3] >> a[4];
  int mx = 0;
  for (int x = -200; x <= 200; x++) {
    a[2] = x;
    int cnt = 0;
    cnt += (a[2] == a[0] + a[1]);
    cnt += (a[3] == a[1] + a[2]);
    cnt += (a[4] == a[2] + a[3]);
    mx = max(mx, cnt);
  }
  cout << mx << '\n';
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