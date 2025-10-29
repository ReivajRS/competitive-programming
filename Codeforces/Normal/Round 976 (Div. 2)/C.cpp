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
  ll b, c, d;
  cin >> b >> c >> d;

  ll a = 0;
  for (int i = 0; i < 61; i++) {
    bool on_b = (b >> i) & 1;
    bool on_d = (d >> i) & 1;
    if (on_d && !on_b) {
      a |= (1ll << i);
    }
    if (!on_d && on_b) {
      a |= (1ll << i);
    }
  }

  if ((a | b) - (a & c) != d) a = -1;
  cout << a << ENDL;
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