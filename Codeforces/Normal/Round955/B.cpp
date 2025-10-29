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
  ll x, y, k;
  cin >> x >> y >> k;

  ll d = y - x % y;
  
  while (k > 0 && d <= k) {
    k -= d;
    x += d;
    
    while (x > 1 && x % y == 0) {
      x /= y;
    }
    d = y - x % y;

    if (x == 1) {
      break;
    }
  }

  x += k % d;
  while(x > 1 && x % y == 0) {
    x /= y;
  }

  cout << x << ENDL;
}

signed main() { __
  int tc;
  cin >> tc;
  while (tc--) {
    // cerr << "CASO" << ENDL;
    solve();
  }
  return 0;
}