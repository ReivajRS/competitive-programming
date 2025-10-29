#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (int i = (int)a; i < (int)b; ++i)
#define ROF(i, a, b) for (int i = (int)a - 1; i >= (int)b; --i)
#define ENDL '\n'

using ld = long double;

void solve() {
  int n;
  cin >> n;
  int y[2];
  cin >> y[0] >> y[1];
  ld l = y[1] == 0 ? 1e9 : 1.0 / y[1];
  ld r = y[0] == 0 ? 1e9 : 1.0 / y[0];
  for (int i = 2; i <= n; i++) {
    int y[2];
    cin >> y[0] >> y[1];
    ld li = y[1] == 0 ? 1e9 : 1.0 * i / y[1];
    ld ri = y[0] == 0 ? 1e9 : 1.0 * i / y[0];
    if (li > r || ri < l) {
      cout << "-1" << ENDL;
      return;
    }
    l = max(l, li);
    r = min(r, ri);
  }
  cout << fixed << setprecision(9);
  cout << min(l, r) << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  
  return 0;
}