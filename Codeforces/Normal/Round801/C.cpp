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
  ll n;
  cin >> n;
  vi a(n);
  for (auto &x : a)
    cin >> x;

  ll cnt1 = 0, cnt2 = 0;
  if ((n - 2) % 2 != 0) {
    for (ll i = 1; i < n - 1; i += 2) {
      if (a[i] > a[i - 1] && a[i] > a[i + 1])
        continue;
      cnt1 += max(a[i - 1], a[i + 1]) + 1 - a[i];
    }
    cout << cnt1 << ENDL;
    return;
  }

  for (ll i = 2; i < n - 1; i += 2) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1])
      continue;
    cnt2 += max(a[i - 1], a[i + 1]) + 1 - a[i];
  }

  vector<vi> dp(n, vi(2, -1));
  auto fun = [&](auto self, int i, bool f) -> ll {
    if (i >= n - 1)
      return 0;
    if (dp[i][f] != -1)
      return dp[i][f];
    ll mx = max(a[i - 1], a[i + 1]) + 1;
    dp[i][f] = a[i] >= mx ? 0 : mx - a[i];
    ll op1 = self(self, i + 2, f), op2 = 1e18;
    if (!f)
      op2 = self(self, i + 3, 1);
    return dp[i][f] += min(op1, op2);
  };

  cout << min(fun(fun, 1, 0), cnt2) << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}