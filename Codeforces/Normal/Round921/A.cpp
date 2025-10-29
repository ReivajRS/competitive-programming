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
  int n, k;
  cin >> n >> k;
  string s;
  FOR (i, 0, k) {
    s.pb(i + 'a');
  }
  string s2, ans;
  FOR (i, 0, n) {
    s2 = s;
    if (i&1)
      reverse(ALL(s2));
    for (auto &c : s2)
      ans.pb(c);
  }
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