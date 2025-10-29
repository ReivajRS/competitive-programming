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
  int m;
  cin >> m;
  map<int, int, greater<int>> mp;
  while (m--) {
    int q, x;
    cin >> q >> x;
    if (q == 1) {
      mp[1 << x]++;
      continue;
    }
    for (auto &[k, v] : mp)
      x -= k * min(x / k, v);
    cout << (x == 0 ? "YES" : "NO") << ENDL;
  }
}

signed main() { __
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}