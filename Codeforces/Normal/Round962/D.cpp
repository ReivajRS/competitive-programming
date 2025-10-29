#include <bits/stdc++.h>
using namespace std;
// Pura gente del coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'

void solve() {
  ll n, x;
  cin >> n >> x;

  auto check = [&](ll c) -> ll {
    ll cnt = 0;
    FOR (a, 1, x - c) {
      ll b = x - c - a;
      // cout << a << ' ' << b << ' ' << c << ENDL;
      if (a == b)
        continue;
      if (a + b + c <= x && a * b + a * c + b * c <= n) {
        cout << a << ' ' << b << ' ' << c << ENDL;
        cnt++;
      }
    }
    FOR (i, 1, x - c) {
      ll a = i, b = i;
      // cout << a << ' ' << b << ' ' << c << ENDL;
      if (a + b + c <= x && a * b + a * c + b * c <= n) {
        cout << a << ' ' << b << ' ' << c << ENDL;
        cnt++;
      }
    }
    return cnt;
  };

  // ll l = 1, r = x;
  // while (l < r) {
  //   ll m = (l + r) / 2;
  //   if (check(m) > 0) {
  //     l = m;
  //   } else {
  //     r = m - 1;
  //   }
  // }

  // ll ans = 0;
  // FOR (i, 1, l + 1) {
  //   ans += check(i);
  // }

  ll ans = 0;
  FOR (i, 1, 5) {
    ans += check(i);
  }

  cout << ans << ENDL;
}

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  
  return 0;
}