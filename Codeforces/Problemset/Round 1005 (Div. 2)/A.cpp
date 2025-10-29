#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;

  int now = 0, ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] - '0' != now) {
      now ^= 1;
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