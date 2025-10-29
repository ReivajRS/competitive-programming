#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), pos(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]] = i;
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    if (pos[i + 1] < pos[i]) {
      ans++;
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