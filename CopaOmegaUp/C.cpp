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

signed main() { __
  ll n;
  cin >> n;

  vi a(n);
  for (auto &x : a) {
    cin >> x;
  }

  ll m;
  cin >> m;

  sort(ALL(a));

  ll l = 0, r = 1e9 + 1;

  auto check = [&](ll d) -> bool {
    ll p = a[0], cnt = 1;
    while (1) {
      auto it = lower_bound(ALL(a), p + d);
      if (it == a.end() || cnt == m)
        break;
      p = a[it - a.begin()];
      cnt++;
    }
    return cnt == m;
  };

  while (r - l > 1) {
    ll mid = l + (r - l) / 2;
    if (check(mid)) {
      l = mid;
    } else {
      r = mid;
    }
  }

  cout << l << ENDL;

  return 0;
}