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
  ll n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n << ENDL;
    return;
  }
  ll cnt = 0;
  while (n) {
    if (k > n) {
      cnt += n;
      n = 0;
      break;
    }
    ll x = 1;
    while (1) {
      if (x * k > n) {
        break;
      }
      x *= k;
    }
    n -= x;
    cnt++;
  }
  cout << cnt << ENDL;
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