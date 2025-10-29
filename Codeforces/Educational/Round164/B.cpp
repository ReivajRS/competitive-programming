#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  int n;
  cin >> n;
  vi a(n);
  for (auto &x : a)
    cin >> x;
  vi df;
  FOR (i, 0, n)
    if (a[i] != a[0])
      df.pb(i);
  if (!SZ(df)) {
    cout << -1 << ENDL;
    return;
  }
  int ans = 1e9;
  ans = min(ans, df[0]);
  ans = min(ans, n - df.back() - 1);
  FOR (i, 1, SZ(df))
    ans = min(ans, df[i] - df[i - 1] - 1);
  cout << ans << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}