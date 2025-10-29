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
  ll n, k;
  cin >> n >> k;
  
  vi a(n), x(n);
  for (auto &v : a)
    cin >> v;
  for (auto &v : x)
    cin >> v;
  
  map<ll, ll> m;
  FOR (i, 0, n) {
    m[abs(x[i])] += a[i];
  }

  queue<ll> pos;
  for (auto &it : m)
    pos.push(it.first);
  
  ll mm = 0;
  while (!pos.empty()) {
    ll bullet = k;
    if (pos.empty())
      break;
    while (bullet >= m[pos.front()] && !pos.empty()) {
      bullet -= m[pos.front()];
      pos.pop();
    }
    if (pos.empty())
      break;
    m[pos.front()] -= bullet;
    mm++;
    if (mm == pos.front()) {
      cout << "NO" << ENDL;
      return;
    }
  }

  cout << "YES" << ENDL;
}

signed main() { __
  ll tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}