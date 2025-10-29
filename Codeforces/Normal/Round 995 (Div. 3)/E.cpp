#include <bits/stdc++.h>
using namespace std;

#define SZ(x) ((int)x.size())
using ll = long long;

void solve() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  for (auto &x : a) cin >> x;
  for (auto &x : b) cin >> x;

  if (n == 1) {
    if (k == 0) {
      cout << a[0] << '\n';
    }
    if (k == 1) {
      cout << b[0] << '\n';
    }
    return;
  }

  vector<pair<ll, ll>> p(n);
  for (int i = 0; i < n; i++) {
    p[i] = {b[i], a[i]};
  }

  sort(p.begin(), p.end());

  /*
    maxnega = 3
    2 3 2 8
    3 7 3 9

    2 2 3 8
    3 3 7 9


    2 3 2 8
    8 7 3 9

    2 3 2 8
    3 7 8 9


    busco en el de abajo, cuantos lo compran. me da r = n - r
    teniendo eso, busco en el de arriba. me da l
    malos = min(0, r - l)

    ll x = !malos * r * precio;
    if ()

    p = 4
    ganancia = 
    malas = 



    2 1
    3 4


  */


  auto check = [&](int from, ll price) -> bool {
    if (from >= n - 1) {
      // cout << -1 << '\n';
      return false;
    }
    // bool flag = false;
    int neg = 0;
    for (int i = from; i < n; i++) {
      if (price > p[i].second) {
        neg++;
        // flag = true;
      }
    }
    // cout << neg << '\n';
    return neg <= k;
  };
  
  // cout << lower_bound(p.begin(), p.end(), pair<ll, ll>(5, 0)) - p.begin() << '\n';
  // cout << check(0, 5) << '\n';

  ll l = 1, r = 1e9 + 5;
  ll ans = 0;
  while (l <= r) {
    ll m = (l + r) / 2;
    ll from = lower_bound(p.begin(), p.end(), pair<ll, ll>(m, 0)) - p.begin();
    // check(buy, m);
    // cout << m << ' ' << from << ' ';
    if (check(from, m)) {
      ll buy = n - from;
      ans = max(ans, buy * m);
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }

  cout << ans << '\n';
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