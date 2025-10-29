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
  int n, p;
  cin >> n >> p;

  ld pp = p / 100.0;
  pp = pow(pp, n - 1);

  ld l = p / 100.0, r = 1.0;
  FOR (i, 0, 200) {
    ld m = (l + r) / 2.0;
    if (pow(m, n) > pp) {
      r = m;
    }
    else {
      l = m;
    }
  }
  cout << fixed << setprecision(12);
  cout << 100.0 * l - p << ENDL;
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