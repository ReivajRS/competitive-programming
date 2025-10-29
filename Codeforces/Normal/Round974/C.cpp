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
  ll n;
  cin >> n;

  vi a(n);
  ll sum = 0;
  for (auto &x : a) {
    cin >> x;
    sum += x;
    x = x * 2 * n;
  }
  sort(ALL(a));

  if (n == 1) {
    cout << -1 << ENDL;
    return;
  }

  auto check = [&](ll x) {
    ll avg = sum + x;
    a.back() += x * 2 * n;
    ll pos = lower_bound(ALL(a), avg) - a.begin();
    a.back() -= x * 2 * n;
    return pos;
  };

  ll l = 0, r = 1e12;
  while (l < r) {
    ll m = (l + r) / 2;
    if (check(m) > (n / 2)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }

  if (l == 1e12) {
    l = -1;
  }

  cout << l << ENDL;
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