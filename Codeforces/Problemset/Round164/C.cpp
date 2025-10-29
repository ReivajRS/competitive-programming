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

// sqrt((x2 - x1)² + (y2 - y1)²)

signed main() { __
  int n, m;
  cin >> n >> m;
  
  int mn = min(n, m);
  cout << mn + 1 << ENDL;

  ROF (i, mn + 1, 1) {
    cout << i << ' ' << mn - i << ENDL;
  }

  cout << 0 << ' ' << mn << ENDL;

  return 0;
}