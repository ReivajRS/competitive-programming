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

void solve() {
  int n, q;
  cin >> n >> q;
  vector<string> a(n);
  map<string, vi> mp;
  FOR (i, 0, n) {
    cin >> a[i];
    mp[a[i]].pb(i + 1);
  }
  auto has_common = [](string s1, string s2) -> bool {
    return s1[0] == s2[0] || s1[0] == s2[1] || s1[1] == s2[0] || s1[1] == s2[1];
  };
  auto mov = [&](int x, int y, string s) -> ll {
    auto r = upper_bound(ALL(mp[s]), y);
    auto l = r;
    if (l != mp[s].begin())
      l--;
    ll cnt_l = abs(x - *l) + abs(y - *l);
    ll cnt_r = 1e18;
    if (r != mp[s].end()) {
      cnt_r = abs(x - *r) + abs(y - *r);
    }
    return min(cnt_l, cnt_r);
  };
  auto dist = [&](int x, int y) -> ll {
    ll mn = 1e18;
    for (auto &[f, s] : mp) {
      if (has_common(a[x - 1], f) && has_common(a[y - 1], f)) {
        mn = min(mn, mov(x, y, f));
      }
    }
    if (mn == 1e18)
      return -1;
    return mn;
  };
  auto get = [&](int x, int y) -> ll {
    if (has_common(a[x - 1], a[y - 1])) {
      return abs(x - y);
    }
    return dist(x, y);
  };
  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << dist(x, y) << ENDL;
  }
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