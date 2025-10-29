#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define SZ(x) (int(x.size()))
#define FOR(i,a,b) for(int i = (int)a; i < (int)b; i++)

struct Line {
  mutable ll k, m, p;
  bool operator<(const Line& o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k) {
      x->p = x->m > y->m ? inf : -inf;
    }
    else {
      x->p = div(y->m - x->m, x->k - y->k);
    }
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p){
      isect(x, erase(y));
    }
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  ll base = 0;
  vector<ll> ps(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> ps[i];
    base += ps[i] * i;
    ps[i] += ps[i - 1];
  }

  ll maxIncrement = 0;
  LineContainer lc;
  for (int i = 1; i <= n; ++i) {
    lc.add(i, -ps[i - 1]);
    ll x = ps[i] - ps[i - 1];
    maxIncrement = max(maxIncrement, ps[i - 1] + lc.query(x) - i * x);
  }

  lc.clear();

  for (int i = n; i; --i) {
    lc.add(i, -ps[i]);
    ll x = ps[i] - ps[i - 1];
    maxIncrement = max(maxIncrement, ps[i] + lc.query(x) - i * x);
  }

  ll ans = base + maxIncrement;
  cout << ans << '\n';

  return 0;
}