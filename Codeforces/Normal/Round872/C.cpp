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
  int n, m;
  cin >> n >> m;
  
  vi c(2, 0), a;
  set<int> st;
  FOR (i, 0, n) {
    int x;
    cin >> x;
    if (x == -1)
      c[0]++;
    if (x == -2)
      c[1]++;
    if (x > 0)
      st.insert(x);
  }
  for (auto &x : st) a.pb(x);

  auto greaterThan = [&](int x) -> int {
    int pos = lower_bound(ALL(a), x) - a.begin();
    if (pos == SZ(a) || a[pos] > x) pos--;
    return SZ(a) - (pos + 1);
  };
  auto lessThan = [&](int x) -> int {
    int pos = lower_bound(ALL(a), x) - a.begin();
    if (pos == SZ(a) || a[pos] > x) pos--;
    return pos;
  };

  int ans = 0;
  // Only -1
  ans = max(ans, min(m, c[0] + SZ(a)));
  // Only -2
  ans = max(ans, min(m, c[1] + SZ(a)));

  FOR (i, 0, SZ(a))
    ans = max(ans, 1 + min(a[i] - 1, c[0] + lessThan(a[i])) + min(m - a[i], c[1] + greaterThan(a[i])));

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