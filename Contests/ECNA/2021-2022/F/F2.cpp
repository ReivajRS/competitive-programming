#include <bits/stdc++.h>
using namespace std;
// BRO... CSM
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

#define pb push_back
#define SZ(x) (int) x.size()
#define ALL(x) x.begin(), x.end()
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define ROF(i, a, b) for (int i = a - 1; i >= b; --i)
#define ENDL '\n'
#define __ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const double EPS = 1e-9;

typedef double T;

struct Point {
  T x, y;
  bool operator==(Point p) const { return abs(x - p.x) <= EPS && abs(y - p.y) <= EPS; }
};

double dist(Point p1, Point p2) { return hypot(p1.x - p2.x, p1.y - p2.y); }

struct Circle {
  Point p;
  T r, s;
  Circle(T _x, T _y, T _r, T _s) {
    p.x = _x, p.y = _y, r = _r, s = _s;
  }
  bool operator==(Circle o) const { return p == o.p && abs(r - o.r) <= EPS && abs(s - o.s) <= EPS; }
};

bool intersect(Circle c1, Circle c2) {
  double sum = c1.r + c2.r;
  double d = dist(c1.p, c2.p);
  return d <= sum || d <= c1.r || d <= c2.r;
}

signed main() { __
  int n;
  cin >> n;

  vector<Circle> a;
  vector<bool> f(n, 1);
  int alive = n;

  FOR (i, 0, n) {
    int x, y, r, s;
    cin >> x >> y >> r >> s;
    a.pb(Circle(x, y, r, s));
  }

  auto grow = [&n, &f](vector<Circle> &a, double v) -> void {
    FOR (i, 0, n) {
      if (!f[i])
        continue;
      a[i].r += v * a[i].s;
    }
  };

  auto check = [&a, &f, &n, &grow](double m) -> vector<pair<Circle, vi>> {
    vector<pair<Circle, vi>> ints;
    vector<Circle> c = a;
    grow(c, m);

    vector<bool> vis(n, 0);
    auto dfs = [&c, &vis, &ints, &f, &n](auto self, int u) -> void {
      vis[u] = 1;
      ints.back().second.pb(u);
      FOR (v, 0, n) {
        if (u == v || !f[v] || vis[v] || c[u] == c[v] || !intersect(c[u], c[v]))
          continue;
        self(self, v);
      }
    };
    
    FOR (u, 0, n) {
      if (!f[u] || vis[u])
        continue;
      ints.pb({c[u], vi()});
      dfs(dfs, u);
      if (SZ(ints.back().second) > 1) {
        double x = 0, y = 0, r = 0, s = 0;
        int sz = SZ(ints.back().second);
        FOR (k, 0, sz) {
          Circle circle = c[ints.back().second[k]];
          x += circle.p.x;
          y += circle.p.y;
          r += circle.r * circle.r;
          s = max(s, circle.s);
        }
        ints.back().first = Circle(x / sz, y / sz, sqrt(r), s);
      }
    }

    return ints;
  };

  auto merge = [&a, &f](vector<pair<Circle, vi>> &ret) -> void {
    FOR (i, 0, SZ(ret)) {
      int idx = 0;
      for (auto &v : ret[i].second) {
        f[v] = 0;
        idx = v;
      }
      a[idx] = ret[i].first;
      f[idx] = 1;
    }
  };

  while (alive > 1) {
    while(1) {
      auto ret = check(0);
      if (SZ(ret) == alive)
        break;
      merge(ret);
      alive = SZ(ret);
    }

    if (alive == 1)
      break;

    double mn = 1e12;
    FOR (i, 0, n) {
      if (!f[i])
        continue;
      FOR (j, i + 1, n) {
        if (i == j || !f[j])
          continue;
        double d = max(dist(a[i].p, a[j].p) - a[i].r - a[j].r, 0.0);
        mn = min(mn, d / (a[i].s + a[j].s) + EPS);
      }
    }

    auto ret = check(mn);
    grow(a, mn);
    merge(ret);
    alive = SZ(ret);
  }

  cout << setprecision(8) << fixed;
  FOR (i, 0, n) {
    if (f[i]) {
      cout << a[i].p.x << ' ' << a[i].p.y << ENDL;
      cout << a[i].r << ENDL;
      return 0;
    }
  }

  return 0;
}