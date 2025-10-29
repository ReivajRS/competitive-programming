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

/*
  1000
  1001
  1010
  1011
  1100
  1101
*/

signed main() {
  cin.tie(0)->sync_with_stdio(0);
  
  ll l, r;
  cin >> l >> r;

  for (int i = 61; i >= 0; i--) {
    ll x = 1ll << i;
    if (r >= x && x - 1 >= l) {
      cout << x * 2 - 1 << ENDL;
      return 0;
    }
    l &= ~(1ll << i);
    r &= ~(1ll << i);
  }

  cout << 0 << ENDL;
  
  return 0;
}