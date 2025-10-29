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
  int log = 31 - __builtin_clz(k);
  vi ans;
  FOR (i, 0, 20) {
    if (i != log)
      ans.pb(1 << i);
  }
  ans.pb(k - (1 << log));
  ans.pb(k + 1);
  ans.pb(k + 1 + (1 << log));
  cout << SZ(ans) << ENDL;
  for (auto &x : ans)
    cout << x << ' ';
  cout << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}