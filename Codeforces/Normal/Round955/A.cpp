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
  ll x1, x2, y1, y2;
  cin >> x1 >> x2 >> y1 >> y2;
  if ((x1 <= x2 && y1 >= y2) || (x2 <= x1 && y2 >= y1)) {
    cout << "NO" << ENDL;
  } else {
    cout << "YES" << ENDL;
  }
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}