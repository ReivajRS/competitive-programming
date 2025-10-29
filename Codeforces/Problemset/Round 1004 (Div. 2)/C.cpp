#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

bool check(ll x) {
  while (x) {
    if (x % 10 == 7) {
      return true;
    }
    x /= 10;
  }
  return false;
}

void solve() {
  ll n;
  cin >> n;

  if (check(n)) {
    cout << 0 << '\n';
    return;
  }

  vector<ll> a = {(ll)1e1 - 1, (ll)1e2 - 1, (ll)1e3 - 1, (ll)1e4 - 1, (ll)1e5 - 1, (ll)1e6 - 1, (ll)1e7 - 1, (ll)1e8 - 1, (ll)1e9 - 1, (ll)1e10 - 1, (ll)1e11 - 1, (ll)1e12 - 1};

  int mn = 10;

  for (auto &x : a) {
    ll val = n;
    for (int i = 1; i <= 9; i++) {
      val += x;
      if (check(val)) {
        mn = min(mn, i);
      }
    }
  }

  cout << mn << '\n';
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