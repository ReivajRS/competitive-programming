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
  ll k;
  cin >> k;

  ll l = 1, r = 1e9 + 5;
  while (l < r) {
    ll m = (l + r + 1) / 2;
    if (m * m > k) {
      r = m - 1;
    }
    else {
      l = m;
    }
  }

  ll d1 = abs(l * l - k);
  ll d2 = abs((l + 1) * (l + 1) - k);
  ll x = d1 <= d2 ? l : l + 1;

  cout << k + x << ENDL;
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