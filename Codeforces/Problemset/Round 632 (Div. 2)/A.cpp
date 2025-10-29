#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

void solve() {
  int n, m;
  cin >> n >> m;
  string s(m, 'B');
  s[0] = 'W';
  cout << s << '\n';
  s[0] = 'B';
  for (int i = 1; i < n; i++) {
    cout << s << '\n';
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