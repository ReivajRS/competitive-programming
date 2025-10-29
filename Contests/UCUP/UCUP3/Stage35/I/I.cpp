#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) ((int)x.size())

constexpr int MOD = 998244353;

template<int MOD> struct mi {
  int v; 
  mi():v(0) {}
  mi(ll _v):v(int(_v%MOD)) { v += (v<0)*MOD; }
  mi& operator+=(mi o) { 
    if ((v += o.v) >= MOD) v -= MOD; 
    return *this; }
  mi& operator-=(mi o) { 
    if ((v -= o.v) < 0) v += MOD; 
    return *this; }
  mi& operator*=(mi o) { 
    v = int((ll)v*o.v%MOD); return *this; }
  friend mi be(mi a, ll p) { assert(p >= 0);
    return p==0?1:be(a*a,p/2)*(p&1?a:1); }
  friend mi inv(mi a) { assert(a.v != 0); return be(a,MOD-2); }
  friend mi operator+(mi a, mi b) { return a += b; }
  friend mi operator-(mi a, mi b) { return a -= b; }
  friend mi operator*(mi a, mi b) { return a *= b; }
};
using modint = mi<MOD>;

void solve() {
  int n;
  cin >> n;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  vector<modint> ma(n);
  for (int i = 0; i < n; i++) {
    ma[i] = modint(a[i]);
  }

  vector<modint> pref(n + 1), pref2(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + ma[i];
    pref2[i + 1] = pref2[i] + ma[i] * ma[i];
  }

  modint ans = 0;

  for (int i = 0; i < n; i++) {
    int l = 0, r = 0;
    while (l < n) {
      ll x = a[l] / a[i];
      modint mx = modint(x);
      r = int(lower_bound(a.begin(), a.end(), a[i] * (x + 1)) - a.begin());
      ans += pref2[r] - pref2[l];
      ans -= mx * ma[i] * (pref[r] - pref[l]) * 2;
      ans += mx * mx * ma[i] * ma[i] * (r - l);
      l = r;
    }
  }

  cout << ans.v << '\n';
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