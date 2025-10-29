#include <bits/stdc++.h>
using namespace std;
// Pura Gente del Coach Moy
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;

#define pb push_back
#define SZ(x) ((ll)(x).size())
#define ALL(x) begin(x), end(x)
#define FOR(i, a, b) for (ll i = (ll)a; i < (ll)b; ++i)
#define ROF(i, a, b) for (ll i = (ll)a - 1; i >= (ll)b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve() {
  ll n;
  cin >> n;
  vi a(n);
  for (auto &x : a)
    cin >> x;
  if (is_sorted(ALL(a))) {
    cout << 0 << ENDL;
    return;
  }
  vi leftGreater(n, -1);
  ll mx_idx = 0, mx = a[0];
  FOR (i, 0, n) {
    if (a[i] > mx)
      mx_idx = i, mx = a[i];
    // leftGreater[i] = a[mx_idx] == a[i] ? -1 : mx_idx;
    leftGreater[i] = mx_idx;
  }


  // FOR (i, 0, n) {
  //   cout << leftGreater[i] << ENDL;
  // }

  ll active_cnt = 0;
  map<ll, ll> mp;
  FOR (i, 0, n) {
    // cout << a[leftGreater[i]] - a[i] << ENDL;
    ll dif = a[leftGreater[i]] - a[i];
    // cout << dif << ENDL;
    if (dif > 0)
      active_cnt++, mp[dif]++;
  }

  ll ans = 0;
  ll act = 0;

  while (!mp.empty() && active_cnt > 0) {
    // cout << "sum " << act << ENDL;
    auto mn = mp.lower_bound(act);
    if (mn == mp.end())
      break;
    // cout << mn->first - act << ' ' << mn->second << ENDL;
    ans += (mn->first - act) * (active_cnt + 1);
    active_cnt -= mn->second;
    act = mn->first;
    mp.erase(mn);
  }

  cout << ans << ENDL;

}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}