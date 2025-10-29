#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
  ll k, m;
  mutable ll p;
  bool operator<(const Line &o) const { return k < o.k; }
  bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
  static const ll inf = LLONG_MAX;
  ll div(ll a, ll b) {
    return a / b - ((a ^ b) < 0 && a % b);
  }
  bool isect(iterator x, iterator y) {
    if (y == end()) return x->p = inf, 0;
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y-> k);
    return x->p >= y->p;
  }
  void add(ll k, ll m) {
    auto z = insert({k, m, 0}), y = z++, x = y;
    while (isect(y, z)) z = erase(z);
    if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
    while ((y = x) != begin() && (--x)->p >= y->p)
      isect(x, erase(y));
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

  vector<array<ll, 3>> rectangles(n);
  for (auto &[x, y, a] : rectangles) {
    cin >> x >> y >> a;
  }

  sort(rectangles.begin(), rectangles.end());

  LineContainer cht;
  cht.add(0, 0);

  vector<ll> dp(n + 1);

  for (int i = 0; i < n; i++) {
    auto [x, y, a] = rectangles[i];
    dp[i + 1] = max(dp[i], x * y - a + cht.query(y));
    cht.add(-x, dp[i + 1]);
  }

  cout << dp[n] << '\n';

  return 0;
}