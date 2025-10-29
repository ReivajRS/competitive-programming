#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Line {
  ll k, m;
  mutable ll p;
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
    if (x->k == y->k)
      x->p = x->m > y->m ? inf : -inf;
    else
      x->p = div(y->m - x->m, x->k - y->k);
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

  /*
    4 3 2 5
    0 4 7 9 14
    4 * 1 + 3 * 2 + 2 * 3 + 5 * 4 = 32
    -5 + 4 * 3 = -5 + 12 = +7
    32 + 7 = 39

    i * a[j] + dp(j)

    a[l] * (r - l) - sum(r - l)

    a[l] * r - sum(r)

    si hago un cambio de i a j, a[i] se multiplica por j
    entonces la query se hace en j para obtener a[i]*j
    la linea que se mete es: a[i]x + sum(i) - a[i] * i
    explicacion para un posible futuro:
    a[i] es el valor que se va a mover y este se multiplica por x
    que es la nueva posicion, por lo que se agrega a[i] * x
    se agrega sum(i) - a[i] * i, debido a que cuando este en r voy
    a tener acceso a cosas como sum(r) y para obtener solo lo del rango
    [l, r], meto en la linea la suma ya menos a[i] * i, que es el elemento
    que se cambia.
    la dp queda de la siguiente manera
    dp[i] = max(dp[i - 1], query(j) - sum(j))

    dp[0] = 0
    4x + 0
    dp[1] = query(2) - sum(2) = 8 - 7 = 1
    3x + 7 - 6 = 3x + 1
    dp[2] = query(3) - sum(3) = 12 - 9 = 3
    2x + 9 - 6 = 2x + 3
    dp[3] = query(4) - sum(4) = 16 - 14 = 2


    derecha a izquierda
    a[i]x + sum(i) - a[i] * i

    1 1 2 7 1
    0 1 2 4 11 12

    dp[4] = 0
    1x + 12 - 1 * 5 = 1x + 12 - 5 = 1x + 7
    dp[3] = query(3) - sum(3) = 10 - 4 = 6
    7x + 11 - 28 = 7x + -17
    dp[2] = query(2) - sum(2) = 9 - 2 = 7
    2x + 4 - 6 = 2x - 2
    dp[1] = query(1) - sum(1) = 8 - 1 = 7
    1x + 1 - 2 = 1x - 1
    dp[0] = query(0) - sum(0) = 7 - 0 = 7
  */

  int n;
  cin >> n;

  ll total = 0;
  vector<ll> a(n), sum(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
    total += a[i] * (i + 1);
  }

  LineContainer lcht, rcht;
  ll lmx = 0, rmx = 0;
  lcht.add(a[0], 0);
  for (int i = 2; i <= n; i++) {
    lmx = max(lmx, lcht.query(i) - sum[i]);
    lcht.add(a[i - 1], sum[i] - a[i - 1] * i);
  }
  rcht.add(a[n - 1], sum[n] - a[n - 1] * n);
  for (int i = n - 2; i >= 0; i--) {
    rmx = max(rmx, rcht.query(i) - sum[i]);
    rcht.add(a[i], sum[i + 1] - a[i] * (i + 1));
  }
  
  cout << total + max(lmx, rmx) << '\n';

  return 0;
}