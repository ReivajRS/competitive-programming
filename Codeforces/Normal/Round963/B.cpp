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
  2 2 3 8
  5 2 3 8
  5 7 3 8
  5 15 3 8
  5 15 3 23
*/

/*
  2 2 5 100
  7 2 5 100
  7 9 5 100
  7 109 5 100
  7 109 5 209 400
  7 109 5 609 400
  7 109 5 609 1009
*/

/*
  1 1 2 3 4 6
  1 1 5 3 4 6
  1 1 5 3 9 6
  1 1 5 3 9 15
*/

/*
  1 1 2 2 3 6
  1 1 5 2 3 6
  1 1 5 7 3 6
  1 1 5 7 3 13
*/

void solve() {
  int n;
  cin >> n;
  
  vector<ll> a(n);
  int c = 0;
  for (auto &x : a) {
    cin >> x;
    c += (x & 1);
  }

  if (c == 0 || c == n) {
    cout << 0 << ENDL;
    return;
  }

  sort(ALL(a));

  ll mx = 1;
  for (auto &x : a) {
    if ((x & 1)) {
      mx = max(mx, x);
    }
  }

  auto get1 = [&](ll maxi) -> int {
    int cnt = 0;
    for (auto &x : a) {
      if (!(x & 1)) {
        if (x < maxi) {
          x = x + maxi;
          maxi = max(maxi, x);
          cnt++;
        } else {
          x = 2*x + maxi;
          maxi = max(maxi, x);
          cnt += 2;
        }
      }
      // cout << x << ' ';
    }
    // cout << ENDL;
    return cnt;
  };

  auto get2 = [&](ll maxi) -> int {
    int cnt = 0;
    ROF (i, n, 0) {
      ll x = a[i];
      if (!(x & 1)) {
        if (x < maxi) {
          x = x + maxi;
          maxi = max(maxi, x);
          cnt++;
        } else {
          x = 2*x + maxi;
          maxi = max(maxi, x);
          cnt += 2;
        }
      }
      // cout << x << ' ';
    }
    // cout << ENDL;
    return cnt;
  };

  // cout << get1() << ' ' << get2(mx) << ENDL;

  int ans = min(get1(mx), get2(mx));

  cout << ans << ENDL;
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