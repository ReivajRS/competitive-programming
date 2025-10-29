#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) (ll) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (ll i = a; i < b; ++i)
#define ROF(i, a, b) for (ll i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  ll x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  ll mn = 1e9;
  mn = min(mn, abs(x1-x1) + abs(x1-x2) + abs(x1-x3));
  mn = min(mn, abs(x2-x1) + abs(x2-x2) + abs(x2-x3));
  mn = min(mn, abs(x3-x1) + abs(x3-x2) + abs(x3-x3));
  cout << mn << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}