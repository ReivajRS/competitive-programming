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

void solve() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  int z = 0;
  for (auto &x : a) {
    cin >> x;
    z += (x == 0);
  }
  if (z == n) {
    cout << 0 << ENDL;
    cout << ENDL;
    return;
  }
  vector<ll> ops;
  FOR (i, 0, 40) {
    ll mx = *max_element(ALL(a));
    ll mn = *min_element(ALL(a));
    ll v = round(1.0 * (mx + mn) / 2);
    ops.pb(v);
    bool flag = 1;
    for (auto &x : a) {
      x = abs(x - v);
      flag &= (x == 0);
    }
    if (flag) {
      cout << SZ(ops) << ENDL;
      for (auto &x : ops) {
        cout << x << ' ';
      }
      cout << ENDL;
      return;
    }
  }
  cout << -1 << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}