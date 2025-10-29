#include <bits/stdc++.h>
using namespace std;

using ll = long long;

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
    while ((y = x) != begin() && (--x)->p >= y->p) {
      isect(x, erase(y));
    }
  }
  ll query(ll x) {
    assert(!empty());
    auto l = *lower_bound(x);
    return l.k * x + l.m;
  }
};

struct CentroidDecomposition {
  int n;
  ll ans;
  vector<basic_string<int>> g;
  vector<int> size, a;
  vector<bool> taken; 

  CentroidDecomposition(int n) : n(n), ans(0), g(n), size(n), a(n), taken(n) {}

  void addEdge(int u, int v) {
    g[u].push_back(v), g[v].push_back(u);
  }

  int getSize(int u, int p) {
    size[u] = 1;
    for (int v : g[u]) {
      if (v != p && !taken[v]) {
        size[u] += getSize(v, u);
      }
    }
    return size[u];
  }

  void query(int u, int father, ll p, ll s, int len, LineContainer& lc) {
    ans = max(ans, s + lc.query(len));
    for (int v : g[u]) {
      if (v != father && !taken[v]) {
        query(v, u, p + a[v], s + p + a[v], len + 1, lc);
      }
    }
  }
  
  void update(int u, int father, ll p, ll s, int len, LineContainer& lc) {
    lc.add(p, s);
    for (int v : g[u]) {
      if (v != father && !taken[v]) {https://codeforces.com/group/3Zw9kC8et8/contest/620982/problem/J
        update(v, u, p + a[v], s + ll(len + 1) * a[v], len + 1, lc);
      }
    }
  }

  void process(int centroid) {
    LineContainer lc;
    lc.add(a[centroid], a[centroid]);
    for (int v : g[centroid]) {
      if (!taken[v]) {
        query(v, centroid, a[v], a[v], 1, lc);
        update(v, centroid, a[centroid] + a[v], 2 * a[v] + a[centroid], 2, lc);
      }
    }
    ans = max(ans, lc.query(0));
  }

  void decompose(int centroid = 0, int sz = -1) {
    if (sz < 0) {
      sz = getSize(centroid, -1);
    }
    for (int v : g[centroid]) {
      if (!taken[v] && size[v] * 2 >= sz) {
        size[centroid] = 0;
        decompose(v, sz);
        return;
      }
    }
    taken[centroid] = true;
    
    ans = max(ans, ll(a[centroid]));
    process(centroid);
    reverse(g[centroid].begin(), g[centroid].end());
    process(centroid);

    for (int v : g[centroid]) {
      if (!taken[v]) {
        decompose(v);
      }
    }
  }

  void calc() {
    decompose();
  }
};

signed main() {
  cin.tie(0)->sync_with_stdio(0);

  int n;
  cin >> n;

  CentroidDecomposition cd(n);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    cd.addEdge(u, v);
  }
  for (int i = 0; i < n; ++i) {
    cin >> cd.a[i];
  }

  cd.calc();
  cout << cd.ans << '\n';

  return 0;
}